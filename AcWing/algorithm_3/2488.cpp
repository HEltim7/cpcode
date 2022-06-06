#include<iostream>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=5e4+10;

struct NODE
{
    int l,r;
    multiset<int> s;
} tr[N*4];
int num[N];

int query(int x,int l,int r,int aim){
    if(tr[x].l>=l&&tr[x].r<=r){
        auto it=tr[x].s.lower_bound(aim);
        if(it==tr[x].s.begin()) return 0;
        else return *--it;
    }
    int mid=tr[x].l+tr[x].r>>1;
    int res=0;
    if(mid>=l) res=query(x<<1,l,r,aim);
    if(mid+1<=r) res=max(res,query(x<<1|1,l,r,aim));
    return res;
}

void modify(int x,int pos,int aim){
    tr[x].s.erase(tr[x].s.find(num[pos]));
    tr[x].s.insert(aim);
    if(tr[x].l==tr[x].r) return;
    int mid=tr[x].l+tr[x].r>>1;
    if(pos<=mid) modify(x<<1,pos,aim);
    if(pos>=mid+1) modify(x<<1|1,pos,aim);
}

void build(int x,int l,int r){
    tr[x]={l,r};
    for(int i=l;i<=r;i++) tr[x].s.insert(num[i]);
    if(l==r) return ;
    int mid=l+r>>1;
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    build(1,1,n);
    while(m--){
        int op,a,b,c;
        cin>>op>>a>>b;
        if(op==1) modify(1,a,b),num[a]=b;
        else{
            cin>>c;
            cout<<query(1,a,b,c)<<endl;
        }
    }
    return 0;
}