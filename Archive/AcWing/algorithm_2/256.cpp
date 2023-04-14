#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=6e5+10,M=N*25;

int num[N],root[N];
int tr[M][2],maxid[M];
int n,m,idx;

//add a new column of trie
void add(int id,int bit,int pre,int cur){
    if(bit<0){
        maxid[cur]=id;
        return;
    }
    int t=num[id]>>bit&1;
    if(pre) tr[cur][t^1]=tr[pre][t^1];
    tr[cur][t]=++idx;
    add(id,bit-1,tr[pre][t],tr[cur][t]);
    maxid[cur]=max(maxid[tr[cur][1]],maxid[tr[cur][0]]);
}

int query(int l,int root,int aim){
    int cur=root;
    for(int i=23;i>=0;i--){
        int t=aim>>i&1;
        if(tr[cur][t^1]&&maxid[tr[cur][t^1]]>=l) cur=tr[cur][t^1];
        else cur=tr[cur][t];
    }
    return num[maxid[cur]]^aim;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    maxid[0]=-1;
    root[0]=++idx;
    add(0,23,0,root[0]);
    for(int i=1;i<=n;i++){
        cin>>num[i];
        num[i]^=num[i-1];
        root[i]=++idx;
        add(i,23,root[i-1],root[i]);
    }
    while(m--){
        string op;
        int a,b,c;
        cin>>op>>a;
        if(op.front()=='A'){
            num[n+1]=num[n]^a;
            root[++n]=++idx;
            add(n,23,root[n-1],root[n]);
        }
        else{
            cin>>b>>c;
            cout<<query(a-1,root[b-1],num[n]^c)<<endl;
        }
    }
    return 0;
}