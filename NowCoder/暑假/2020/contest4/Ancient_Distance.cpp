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

void solve(int n) {
    vector<int> p(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=2;i<=n;i++) {
        cin>>p[i];
        adj[p[i]].emplace_back(i);
    }

    int maxd=0;
    vector<vector<int>> lay(n+1);
    auto init=[&](auto self,int u,int dep) -> void {
        maxd=max(maxd,dep);
        lay[dep].emplace_back(u);
        for(int v:adj[u]) {
            self(self,v,dep+1);
        }
    };
    init(init,1,1);

    auto check=[&](int k,int d) {
        int res=0;
        vector<int> dis(n+1,d+1);
        for(int i=maxd;i>=1;i--) {
            for(int u:lay[i]) {
                if(dis[u]>d) {
                    dis[u]=d;
                    res++;
                }
                if(dis[u]) dis[p[u]]=min(dis[p[u]],dis[u]-1);
            }
        }
        return res<=k;
    };

    int sum=0;
    for(int k=1;k<=n;k++) {
        int l=0,r=maxd-1;
        while(l<r) {
            int m=(l+r)/2;
            if(check(k,m)) r=m;
            else l=m+1;
        }
        sum+=l;
    }
    cout<<sum<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while(cin>>n) solve(n);
    return 0;
}