#include<iostream>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
typedef long long LL;
const int N=2e7+10,M=1e7+1;
int tr[N],bit=24;

inline void add(int pos,int val){
    pos+=M;
    while(pos<N) tr[pos]+=val,pos+=lowbit(pos);
}

inline int query(int pos){
    pos+=M;
    int res=0;
    while(pos) res+=tr[pos],pos-=lowbit(pos);
    return res;
}

int kth(int k){
    int pos=0;
    for(int i=bit;~i;i--)
        if(pos+(1<<i)<N&&tr[pos+(1<<i)]<k) 
            pos+=1<<i,k-=tr[pos]; 
    return pos+1-M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,op,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op>>x;
        if(op==1) add(x,1);
        else if(op==2) add(x,-1);
        else if(op==3) cout<<query(x-1)+1<<endl;
        else if(op==4) cout<<kth(x)<<endl;
        else if(op==5) cout<<kth(query(x-1))<<endl;
        else cout<<kth(query(x)+1)<<endl;
    }
    return 0;
}