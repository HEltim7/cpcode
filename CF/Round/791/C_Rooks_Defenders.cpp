#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
const int N=1e5+10;
int tr[2][N],cnt[2][N];
int n;

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

void add(int id,int pos,int val){
    while(pos<=n) tr[id][pos]+=val,pos+=lowbit(pos);
}

int query(int id,int pos){
    int res=0;
    while(pos) res+=tr[id][pos],pos-=lowbit(pos);
    return res;
}

void add_rock(int r,int c){
    if(++cnt[0][r]==1) add(0,r,1);
    if(++cnt[1][c]==1) add(1,c,1);
}

void del_rock(int r,int c){
    if(--cnt[0][r]==0) add(0,r,-1);
    if(--cnt[1][c]==0) add(1,c,-1);
}

bool check(int u,int d,int l,int r){
    bool res=0;
    debug(u,d,l,r);
    if(query(0,d)-query(0,u-1)==d-u+1) res=1;
    if(query(1,r)-query(1,l-1)==r-l+1) res=1;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int q;
    cin>>n>>q;
    while(q--){
        int t,a,b,c,d;
        cin>>t>>a>>b;
        if(t==1) add_rock(a,b);
        else if(t==2) del_rock(a,b);
        else if(t==3) {
            cin>>c>>d;
            cout<<(check(a,c,b,d)?"Yes":"No")<<endl;
        }
    }
    return 0;
}