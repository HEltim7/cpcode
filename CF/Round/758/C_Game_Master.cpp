#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=1e5+10;
int a[N],b[N];
bool ans[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    queue<int> q;
    map<int,int,greater<int>> mpa,mpb;
    
    int n,mxa=0,mxb=0;
    cin>>n;
    memset(ans,0,sizeof (bool)*(n+1));
    for(int i=1;i<=n;i++) cin>>a[i],mxa=max(mxa,a[i]);
    for(int i=1;i<=n;i++) cin>>b[i],mxb=max(mxb,b[i]);
    for(int i=1;i<=n;i++) {
        mpa.emplace(a[i],i);
        mpb.emplace(b[i],i);
    }
    int id=mpa[mxa];
    ans[id]=1;
    mpa.erase(mxa);
    mpb.erase(b[id]);
    q.push(id);
    if(mpb.count(mxb)) {
        id=mpb[mxb];
        ans[id]=1;
        mpb.erase(mxb);
        mpa.erase(a[id]);
        q.push(id);
    }
    while(q.size()) {
        id=q.front();
        q.pop();
        for(auto it=mpa.begin();it!=mpa.end()&&it->first>a[id];it=mpa.begin()) {
            int t=it->second;
            ans[t]=1;
            mpa.erase(it),mpb.erase(b[t]);
            q.push(t);
        }
        for(auto it=mpb.begin();it!=mpb.end()&&it->first>b[id];it=mpb.begin()) {
            int t=it->second;
            ans[t]=1;
            mpb.erase(it),mpa.erase(a[t]);
            q.push(t);
        }
    }
    for(int i=1;i<=n;i++) cout<<ans[i];
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