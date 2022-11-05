#include <map>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
using TIII=tuple<int,int,int>;
constexpr int N=2e5+10;

template<typename T=int> 
struct Fenwick {
    std::vector<T> tr;
    int sz=0;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,T &val) {
        aim+=val;
    }

    void add(int pos,T val) {
        while(pos<=sz) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res=0;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    Fenwick(int n) { tr.resize(sz=n+1); }
};

struct Point {
    int a,b,c,id;
} arr[N],bak[N];

Fenwick<> tr(N);
int ans[N],f[N],cnt[N];

void solve(int l,int r) {
    int mid=(l+r)/2;
    for(int i=l;i<=r;i++) arr[i]=bak[i];
    sort(arr+l,arr+mid+1,[](const Point &x,const Point &y){
        return x.b<y.b;
    });
    sort(arr+mid+1,arr+r+1,[](const Point &x,const Point &y){
        return x.b<y.b;
    });
    
    for(int i=l,j=mid+1;i<=mid||j<=r;) {
        if(i<=mid&&arr[i].b<=arr[j].b||j>r) tr.add(arr[i].c, cnt[arr[i].id]),i++;
        else f[arr[j].id]+=tr.query(arr[j].c),j++;
    }
    for(int i=l;i<=mid;i++) tr.add(arr[i].c, -cnt[arr[i].id]);

    if(mid>l) solve(l,mid);
    if(r>mid+1) solve(mid+1,r);
}

void solve() {
    map<LL,int> idmp;
    int n,k,bakn;
    cin>>n>>k;
    bakn=n;
    for(int i=1,a,b,c;i<=n;) {
        cin>>a>>b>>c;
        LL cur=1LL*a*N*N+1LL*b*N+c;
        auto it=idmp.find(cur);
        if(it==idmp.end()) {
            idmp[cur]=i;
            bak[i]={a,b,c,i};
            cnt[i]++;
            i++;
        }
        else {
            cnt[it->second]++;
            f[it->second]++;
            n--;
        }
    }
    sort(bak+1,bak+1+n,[](const Point &x,const Point &y){
        if(x.a!=y.a) return x.a<y.a;
        else if(x.b!=y.b) return x.b<y.b;
        return x.c<y.c;
    });
    
    solve(1,n);
    for(int i=1;i<=n;i++) ans[f[i]]+=cnt[i];
    for(int i=0;i<bakn;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}