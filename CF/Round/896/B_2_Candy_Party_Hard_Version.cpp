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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

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
    vector<int> cnt(64),low(64);
    for(int x:arr) {
        if(x!=avg) {
            int t=abs(x-avg);
            for(int i=lowbit(t)+1;i<__lg(t);i++) {
                if(t>>i&1^1) {
                    cout<<"No"<<endl;
                    return;
                }
            }
            if(t==1<<__lg(t)) {
                if(x>avg) low[__lg(t)]++;
                else low[__lg(t)]--;
            }
            else {
                if(x>avg) cnt[__lg(t)+1]++,cnt[lowbit(t)]--;
                else cnt[__lg(t)+1]--,cnt[lowbit(t)]++;
            }
        }
    }
    debug(cnt);
    debug(low);

    for(int i=0;i<64;i++) {
        debug(i,cnt[i]);
        if(abs(low[i])<abs(cnt[i])||((abs(low[i])-abs(cnt[i]))%2)) {
            cout<<"No"<<endl;
            return;
        }
        
        int x=abs(cnt[i]);
        int y=abs(low[i])-abs(cnt[i]);
        x+=y/2,y/=2;

        if(cnt[i]<0) {
            if(low[i]<0) cnt[i+1]-=x;
            else cnt[i+1]+=y;
        }
        else {
            if(low[i]>0) cnt[i+1]+=x;
            else cnt[i+1]-=y;
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