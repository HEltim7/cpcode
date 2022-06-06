#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

#define endl '\n'

const int N=2e5+10;
int h[N],ne[N],e[N],w[N],idx;
bool ans;

inline void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
    e[idx]=a,ne[idx]=h[b],h[b]=idx++;
}

void dfs(int root,int fa,int val){
    if(ans==0) return;
    int cnt=0;
    for(int i=h[root];~i;i=ne[i]){
        int ver=e[i];
        cnt++;
        if(cnt==3) ans=0;
        if(ver==fa) continue;
        w[i]=val,dfs(ver,root,val^1);
        val^=1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(h,-1,sizeof (int)*(n*2+1));
        memset(w,0,sizeof (int)*(2*n+1));
        idx=0;
        ans=1;
        for(int i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            add(a,b);
        }
        dfs(1,0,2);
        if(ans){
            for(int i=0;i<idx;i++) if(w[i]) cout<<w[i]<<' ';
        }
        else cout<<"-1";
        cout<<endl;
    }
    return 0;
}