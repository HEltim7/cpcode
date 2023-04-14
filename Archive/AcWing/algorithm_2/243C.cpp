#include<iostream>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
typedef long long LL;
const int N=1e5+10;

LL tr1[N],tr2[N];
int n;

inline void add(int pos,LL val){
    int tmp=pos;
    while(pos<=n) tr1[pos]+=val,tr2[pos]+=tmp*val,pos+=lowbit(pos);
}

inline LL sum(int pos){
    LL res=0;
    int tmp=pos;
    while(tmp) res+=tr1[tmp],tmp-=lowbit(tmp);
    res*=(pos+1);
    while(pos) res-=tr2[pos],pos-=lowbit(pos);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        add(i,in),add(i+1,-in);
    }
    while(m--){
        char op;
        int a,b,c;
        cin>>op>>a>>b;
        if(op=='Q') cout<<sum(b)-sum(a-1)<<endl;
        else {
            cin>>c;
            add(a,c),add(b+1,-c);
        }
    }
    return 0;
}