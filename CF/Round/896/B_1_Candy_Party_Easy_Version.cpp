#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int &x:arr) cin>>x;
    LL sum=accumulate(arr.begin(),arr.end(),0LL);
    if(sum%n) {
        cout<<"No"<<endl;
        return;
    }

    auto lowbit=[&](int x) {
        return __lg(x&(-x));
    };

    int avg=sum/n;
    vector<int> cnt(64);
    for(int x:arr) {
        if(x!=avg) {
            int t=abs(x-avg);
            for(int i=lowbit(t)+1;i<__lg(t);i++) {
                if(t>>i&1^1) {
                    cout<<"No"<<endl;
                    return;
                }
            }
            if(x>avg) cnt[__lg(t)+1]++,cnt[lowbit(t)]--;
            else cnt[__lg(t)+1]--,cnt[lowbit(t)]++;
        }
    }

    for(int x:cnt) {
        if(x) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}