#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

template<typename T> vector<T> get_prime_factor(T x) {
    vector<T> res;
    for(T i=2;i*i<=x;i++) {
        if(x%i==0) {
            while(x%i==0) x/=i;
            res.push_back(i);
        }
    }
    if(x>1) res.push_back(x);
    return res;
}

template<typename T> vector<T> get_factor(T x) {
    vector<T> res;
    for(T i=1;i*i<=x;i++) {
        if(x%i==0) {
            res.push_back(i);
            if(x/i!=i) res.push_back(x/i);
        }
    }
    return res;
}

void solve() {
    int n;
    cin>>n;
    if(n==1) cout<<"a"<<endl;
    else if(n==2) cout<<"is"<<endl;
    else {
        auto &&v=get_factor(n);
        sort(v.begin(),v.end());
        int idx=-1;
        for(int i=0;i<v.size();i++) {
            if(v[i]!=i+1) {
                idx=i+1;
                break;
            }
        }
        assert(idx!=-1&&idx<=26);

        for(int i=0;i<n;i++) {
            cout<<char('a'+i%idx);
        }
        cout<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}