#include <algorithm>
#include <array>
#include <cassert>
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
    int n,k;
    cin>>n>>k;
    auto &&num=get_prime_factor(n+2);
    
    auto count=[&](int x) {
        int pre=0;
        for(int i=1;i<1<<num.size();i++) {
            int sign=__builtin_popcount(i)&1?1:-1;
            int prod=1;
            for(int j=0;j<num.size();j++) {
                if(i>>j&1) prod*=num[j];
            }
            pre+=sign*x/prod;
        }
        return x-pre;
    };

    int tot=count(n+2);
    if(tot<k) {
        cout<<-1<<endl;
        return;
    }

    int L=1,R=n+1;
    while(L<R) {
        int mid=L+R>>1;
        if(count(mid)>=k) R=mid;
        else L=mid+1;
    }

    int l=L,r=n+2-l;
    bool front=l>r;
    vector<int> ans;
    
    while(l&&r) {
        assert(l!=r);
        if(l<r) swap(l,r);
        int t=l/r;
        l-=t*r;
        ans.emplace_back(t);
    }
    ans.back()--;
    cout<<ans.size()<<' '<<front<<endl;
    for(int x:ans) cout<<x<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}