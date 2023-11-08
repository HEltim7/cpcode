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
    int n,m;
    cin>>n;
    vector<int> num;
    auto arr=vector(2,vector<pair<int,int>>());
    arr[0].resize(n);
    for(auto &[a,d]:arr[0]) cin>>a,num.push_back(a);
    for(auto &[a,d]:arr[0]) cin>>d,num.push_back(d);
    cin>>m;
    arr[1].resize(m);
    for(auto &[a,d]:arr[1]) cin>>a,num.push_back(a);
    for(auto &[a,d]:arr[1]) cin>>d,num.push_back(d);
    
    num.push_back(0);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    auto get=[&](int x) {
        return lower_bound(num.begin(),num.end(),x)-num.begin();
    };

    int mx=num.size()+5;
    auto mxd=vector(2,vector<int>(mx));
    auto mxid=vector(2,vector<int>(mx));

    for(int i=0;i<=1;i++) {
        int r=i==0?n:m;
        for(int j=0;j<r;j++) {
            auto &[x,y]=arr[i][j];
            x=get(x),y=get(y);
            if(y>mxd[i][x]) {
                mxd[i][x]=y;
                mxid[i][x]=j;
            }
        }
        for(int j=mx-2;j>=0;j--) {
            if(mxd[i][j]<mxd[i][j+1]) {
                mxd[i][j]=mxd[i][j+1];
                mxid[i][j]=mxid[i][j+1];
            }
        }
    }

    vector<pair<bool,int>> path;
    auto inq=vector{vector<bool>(n),vector<bool>(m)};
    auto mark=vector{vector<bool>(n),vector<bool>(m)};
    auto dp=vector{vector<int>(n),vector<int>(m)};
    function<int(bool,int)> dfs=[&](bool b,int id) {
        path.emplace_back(b,id);
        if(inq[b][id]) return 0;
        if(mark[b][id]) return dp[b][id];
        int curd=arr[b][id].second;
        int ned=mxd[!b][curd+1];
        int neid=mxid[!b][curd+1];
        inq[b][id]=1;
        mark[b][id]=1;
        if(!ned) return dp[b][id]=1;
        return dp[b][id]=-dfs(!b,neid);
    };

    vector<int> ans(3);
    for(int i=0;i<n;i++) {
        path.clear();
        ans[dfs(0,i)+1]++;
        for(auto [b,id]:path) inq[b][id]=0;
    }
    cout<<ans[2]<<' '<<ans[1]<<' '<<ans[0]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}