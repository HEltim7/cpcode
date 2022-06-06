#include<iostream>
using namespace std;

int n,m;
const int N=1e5+10;
int h[N],e[N],ne[N],in[N],idx;
int q[N],qh=1,qt=0;

void insert(int a,int b){
    e[++idx]=b,ne[idx]=h[a],h[a]=idx,in[b]++;
}

void topsort(){
    for(int i=1;i<=n;i++){
        if(in[i]==0) q[++qt]=i;
    }
    while(qh<=qt){
        for(int i=h[q[qh]];i;i=ne[i]){
            int j=e[i];
            in[j]--;
            if(in[j]==0) q[++qt]=j;
        }
        qh++;
    }
    if(qt<n) cout<<-1;
    else for(int i=1;i<=qt;i++) cout<<q[i]<<' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        insert(a,b);
    }
    topsort();
    return 0;
}