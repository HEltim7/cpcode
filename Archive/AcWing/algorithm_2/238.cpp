#include<iostream>
using  namespace std;

#define endl '\n'

//dist表示当前节点到根的距离，len表示当前列长
const int N=3e4+10;
int fa[N],dist[N],len[N];
int d;

int findfa(int x){
    if(fa[x]==x){
        d=0;
        return x;
    }
    fa[x]=findfa(fa[x]);
    dist[x]+=d;
    d=dist[x];
    return fa[x];
}

void merge(int a,int b){
    a=findfa(a),b=findfa(b);
    if(a==b) return ;
    fa[a]=b;
    dist[a]=len[b];
    len[b]+=len[a];
}

int query(int a,int b){
    if(findfa(a)!=findfa(b)) return -1;
    if(a==b) return 0;
    findfa(a),findfa(b);
    return abs(dist[a]-dist[b])-1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(int i=1;i<N;i++) fa[i]=i;
    for(int i=1;i<N;i++) len[i]=1;
    int t;
    cin>>t;
    while(t--){
        int a,b;
        char cmd;
        cin>>cmd>>a>>b;
        if(cmd=='M') merge(a,b);
        else cout<<query(a,b)<<endl;
    }
    return 0;
}