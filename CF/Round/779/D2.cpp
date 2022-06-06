#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e6+10,M=20,H=17;
int n,l,r;
int arr[N];

struct NODE {
    int ch[2];
    inline void init() { ch[0]=ch[1]=0; }
} tr[N];
int idx;

int getxor(int x,int val,int bit,bool type){
    if(bit<0) return 0;
    int s=(val>>bit)&1;
    if(type&&tr[x].ch[s^1]) s^=1;
    if(!type&&!tr[x].ch[s]) s^=1;
    return (s<<bit)+getxor(tr[x].ch[s],val,bit-1,type);
}

void build(int x,int val,int bit){
    if(bit<0) return;
    int s=(val>>bit)&1;
    if(tr[x].ch[s]==0) tr[x].ch[s]=++idx,tr[idx].init();
    build(tr[x].ch[s],val,bit-1);
}

void solve(){
    tr[0].init();
    idx=0;
    cin>>l>>r;
    n=r-l+1;
    for(int i=1;i<=n;i++) cin>>arr[i],build(0,arr[i],H);

    for(int i=1;i<=n;i++){
        int x=arr[i]^l;
        if((x^getxor(0,x,H,1))<=r&&(x^getxor(0,x,H,0))>=l){
            cout<<x<<endl;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}