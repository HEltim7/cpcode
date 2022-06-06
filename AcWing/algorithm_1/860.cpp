#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=2e5+10;
int n,m;
int e[N],ne[N],color[N],h[N],idx;
int fa[N];
bool mark[N];
bool flag;

void add(int a,int b){
    e[++idx]=b,ne[idx]=h[a],h[a]=idx;
}

void dfs(int loc,int c){
    if(flag) return;
    int id=e[loc];
    color[id]=c;
    for(int i=h[id];i;i=ne[i]){
        int j=e[i];
        if(!color[j]){
            dfs(i,3-c);
        }
        else if(color[j]!=3-c){
            flag=1;
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    for(int i=1;i<=2*m;i+=2){
        if(!color[e[i]]) dfs(i,1);
        if(flag) break;
    }
    if(flag) cout<<"No";
    else cout<<"Yes";
    return 0;
}