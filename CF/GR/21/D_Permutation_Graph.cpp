#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=3e5+10;
int arr[N],maxx[20][N],minn[20][N];

int qpow(int a,int b) {
    int res=1;
    while(b) {
        if(b&1) res=res*a;
        b>>=1;
        a=a*a;
    }
    return res;
}

int query_maxx(int l,int r) {
    if(l==r) return l;
    int len=r-l+1,t=0;
    while(qpow(2,t+1)<=len) t++;
    if(arr[maxx[t][l]]>arr[maxx[t][r-qpow(2,t)+1]]) return maxx[t][l];
    return maxx[t][r-qpow(2,t)+1];
}

int query_minn(int l,int r) {
    if(l==r) return l;
    int len=r-l+1,t=0;
    while(qpow(2,t+1)<=len) t++;
    if(arr[minn[t][l]]<arr[minn[t][r-qpow(2,t)+1]]) return minn[t][l];
    return minn[t][r-qpow(2,t)+1];
}

int dfs(int l,int r) {
    int res=0;
    int mx=query_maxx(l,r);
    int mn=query_minn(l,r);
    assert(mx&&mn);
    if(mx<mn) swap(mx,mn);
    if(mx!=mn) res++;
    if(mn!=l) res+=dfs(l,mn);
    if(mx!=r) res+=dfs(mx,r);
    return res;
}

void solve() {
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++) cin>>arr[i],maxx[0][i]=minn[0][i]=i;
    for(int k=1;qpow(2,k)<=n;k++) {
        for(int i=1;i+qpow(2,k)-1<=n;i++) {
            int t=i+qpow(2,k-1);
            if(arr[maxx[k-1][i]]>arr[maxx[k-1][t]])
                maxx[k][i]=maxx[k-1][i];
            else maxx[k][i]=maxx[k-1][t];
            if(arr[minn[k-1][i]]<arr[minn[k-1][t]])
                minn[k][i]=minn[k-1][i];
            else minn[k][i]=minn[k-1][t];
        }
    }
    cout<<dfs(1,n)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}