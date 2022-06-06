#include<iostream>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
const int N=1e5+10;
int tr[N],n;

inline void add(int pos,int val){
    while(pos<=n) tr[pos]+=val,pos+=lowbit(pos);
}

inline int sum(int pos){
    int res=0;
    while(pos) res+=tr[pos],pos-=lowbit(pos);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        add(i,in),add(i+1,-in);
    }
    while(m--){
        char op;
        cin>>op;
        int a,b,c;
        if(op=='Q'){
            cin>>a;
            cout<<sum(a)<<endl;
        }
        else{
            cin>>a>>b>>c;
            add(a,c),add(b+1,-c);
        }
    }
    return 0;
}