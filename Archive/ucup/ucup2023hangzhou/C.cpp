#include <algorithm>
#include <array>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
vector<int> adj[N];
int type[N],dep[N],id[N],ed[N],p[N],idx;
bool pass[N];
vector<pair<int,int>> ans;

void init(int u) {
    id[u]=++idx;
    for(int v:adj[u]) {
        dep[v]=dep[u]+1;
        init(v);
    }
    ed[u]=idx;
}

void no() {
    cout<<"NO"<<endl;
    exit(0);
};

void jump(int u,int v) {
    if(dep[u]<dep[v]) swap(u,v);
    if(type[u]==2&&type[v]==3) no();
    if(type[u]==1&&type[v]==1&&dep[u]!=dep[v]) no();
    ans.emplace_back(u,v);
    while(u!=v) {
        if(dep[u]<dep[v]) swap(u,v);
        if(pass[u]) no();
        pass[u]=1;
        u=p[u];
    }
};

int dfs(int u) {
    vector<int> lng,sht,equ,unpair;
    auto push=[&](int x) {
        if(type[x]==1) equ.emplace_back(x);
        if(type[x]==2) sht.emplace_back(x);
        if(type[x]==3) lng.emplace_back(x);
    };
    for(int v:adj[u]) push(dfs(v));
    push(u);
    if(abs(int(lng.size())-int(sht.size()))>=2) no();
    bool flag=lng.size()>=sht.size();

    auto cmp=[&](int x,int y) { return flag?dep[x]<dep[y]:dep[x]>dep[y]; };
    sort(lng.begin(),lng.end(),cmp);
    sort(sht.begin(),sht.end(),cmp);
    sort(equ.begin(),equ.end(),cmp);

    for(int i=0;i<equ.size();) {
        if(i+1<equ.size()&&dep[equ[i]]==dep[equ[i+1]]) jump(equ[i], equ[i+1]),i+=2;
        else unpair.emplace_back(equ[i]),i++;
    }

    for(int i=0,j=0;i<sht.size()||j<lng.size();) {
        if(i>=sht.size()) unpair.emplace_back(lng[j++]);
        else if(j>=lng.size()) unpair.emplace_back(sht[i++]);
        else {
            if(dep[sht[i]]<dep[lng[j]]) jump(sht[i++], lng[j++]);
            else unpair.emplace_back(flag?lng[j++]:sht[i++]);
        }
    }

    if(unpair.size()>=2) no();
    if(unpair.empty()) return 0;
    return unpair.front();
}

void solve() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) {
        cin>>p[i]>>p[i];
        adj[p[i]].push_back(i);
        string s;
        cin>>s;
        if(s=="Tong") type[i]=1;
        else if(s=="Duan") type[i]=2;
        else if(s=="Chang") type[i]=3;
    }
    dep[1]=1;
    init(1);

    if(dfs(1)) no();
    cout<<"YES"<<endl;
    for(auto [x,y]:ans) cout<<x<<' '<<y<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}