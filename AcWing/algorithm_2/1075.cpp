#include<iostream>
#include<cstring>
using namespace std;

#define point first
#define dis second

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef pair<int,int> PII;

const int N=2e5+10;
int sum[N];
int n;
int e[N],ne[N],h[N],idx;

void add(int a,int b){
    e[++idx]=b,ne[idx]=h[a],h[a]=idx;
}

void count(){
    for(int i=1;i<=n;i++){
        for(int j=2;j<=n/i;j++){
            if(sum[i*j]==-1) continue;
            if(sum[i*j]+i>n){
                sum[i*j]=-1;
                continue;
            }
            sum[i*j]+=i;
        }
    }
}

void build(){
    for(int i=2;i<=n;i++){
        if(sum[i]==-1||sum[i]>i) continue;
        add(i,sum[i]);
        add(sum[i],i);
    }
}

//搜索到当前点最远的点
PII dfs(int id,int root){
    PII res;
    res.point =id;
    for(int i=h[id];i;i=ne[i]){
        int poi=e[i];
        if(poi==root) continue;
        PII tmp=dfs(poi,id);
        tmp.dis++;
        if(tmp.dis>res.dis) res=tmp;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    count();
    build();
    cout<<dfs(dfs(1,-1).point,-1).dis;
    return 0;
}