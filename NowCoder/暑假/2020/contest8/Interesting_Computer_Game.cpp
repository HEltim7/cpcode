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

int solve() {
    int n;
    cin>>n;
    vector<int> a(n),b(n),num;
    for(int i=0;i<n;i++) {
        cin>>a[i]>>b[i];
        num.emplace_back(a[i]);
        num.emplace_back(b[i]);
    }

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=0;i<n;i++) {
        a[i]=lower_bound(num.begin(),num.end(),a[i])-num.begin();
        b[i]=lower_bound(num.begin(),num.end(),b[i])-num.begin();
    }
    
    int mx=num.size();
    vector<int> cnt(mx);
    vector<vector<pair<int,int>>> pos(mx);
    for(int i=0;i<n;i++) {
        cnt[a[i]]++;
        cnt[b[i]]++;
        pos[a[i]].emplace_back(i,0);
        pos[b[i]].emplace_back(i,1);
    }

    set<int> st;
    queue<int> q;
    vector<bool> take(n);
    for(int i=0;i<mx;i++) if(cnt[i]==1) q.emplace(i);
    while(q.size()) {
        int x=q.front();
        q.pop();
        for(auto [r,s]:pos[x]) {
            if(take[r]) continue;
            take[r]=1;
            st.emplace(x);
            if(s==0) {
                if(--cnt[b[r]]==1) q.emplace(b[r]);
            }
            else {
                if(--cnt[a[r]]==1) q.emplace(a[r]);
            }
        }
    }

    for(int i=0;i<n;i++) if(!take[i]) st.emplace(a[i]),st.emplace(b[i]);
    return st.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cout<<"Case #"<<i<<": "<<solve()<<endl;
    }
    return 0;
}