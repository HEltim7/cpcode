#include<iostream>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
const int N=1e5+10;

int tr[N],cow[N];
int n;

inline void add(int pos){
    while(pos<=n) tr[pos]-=1,pos+=lowbit(pos);
}

inline int sum(int pos){
    int res=0;
    while(pos) res+=tr[pos],pos-=lowbit(pos);
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) tr[i]=lowbit(i);
    for(int i=2;i<=n;i++) cin>>cow[i],cow[i]++;
    cow[1]=1;
    for(int i=n;i>=1;i--){
        int l=1,r=n;
        while(l<r){
            int mid=l+r>>1;
            if(sum(mid)>=cow[i]) r=mid;
            else l=mid+1;
        }
        cow[i]=l;
        add(l);
    }
    for(int i=1;i<=n;i++) cout<<cow[i]<<endl;
    return 0;
}