#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int a[N],b[N],pa[N],pb[N],n,s;
bool mark[N];

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

bool try_swap(int x,int y) {
    if(abs(a[x]-a[y])<=s) {
        swap(a[x],a[y]);
        swap(pa[a[x]],pa[a[y]]);
        return 1;
    }
    return 0;
}

void solve() {
    cin>>n>>s;
    memset(mark,0,sizeof (bool)*(n+1));
    for(int i=1;i<=n;i++) cin>>a[i],pa[a[i]]=i;
    for(int i=1;i<=n;i++) cin>>b[i],pb[b[i]]=i,mark[b[i]]=1;
    for(int v=1;v<=n;v++) {
        int idx=pa[v];
        debug(a,1,n,v,idx);
        if(b[idx]==-1) {
            if(mark[v]) {
                if(!try_swap(idx,pb[v])) {
                    cout<<0<<endl;
                    return;
                }
            }
            else {
                cout<<"qwq"<<endl;
            }
        }
        else {
            if(a[idx]>b[idx]) {
                cout<<0<<endl;
                return;
            }
            
            else if(a[idx]<b[idx]) {
                if(!try_swap(idx,pa[b[idx]])) {
                    debug(idx,pa[b[idx]]);
                    cout<<0<<endl;
                    return;
                }
            }
            else continue;
        }
    }
    cout<<"finished"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}