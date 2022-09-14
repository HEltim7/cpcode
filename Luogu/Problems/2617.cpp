#include <ostream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

struct Operation {
    int type,x,y,z,id;
} arr[N*3],bak[N*3];
int ans[N],last[N],idx,tot;

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
Fenwick<> tr(N);

void solve(int l,int r,int L,int R) {
    if(l==r) {
        for(int i=L;i<=R;i++) ans[arr[i].id]=l;
        return;
    }
    int mid=l+r>>1,ll=L,rr=R;
    for(int i=L;i<=R;i++) {
        if(arr[i].type==1) {
            if(arr[i].y<=mid) tr.add(arr[i].x, 1),bak[ll++]=arr[i];
            else bak[rr--]=arr[i];
        }
        else if(arr[i].type==-1) {
            if(arr[i].y<=mid) tr.add(arr[i].x, -1),bak[ll++]=arr[i];
            else bak[rr--]=arr[i];
        }
        else {
            int cnt=tr.query(arr[i].y)-tr.query(arr[i].x-1);
            if(arr[i].z<=cnt) bak[ll++]=arr[i];
            else arr[i].z-=cnt,bak[rr--]=arr[i];
        }
    }

    for(int i=L;i<=R;i++) {
        if(arr[i].type==1&&arr[i].y<=mid) tr.add(arr[i].x, -1);
        else if(arr[i].type==-1&&arr[i].y<=mid) tr.add(arr[i].x, 1);
    }
    
    for(int i=L;i<=rr;i++) arr[i]=bak[i];
    for(int i=R;i>=ll;i--) arr[i]=bak[ll+R-i];
    if(L<=rr) solve(l, mid, L, rr);
    if(ll<=R) solve(mid+1, r, ll, R);
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> num;
    for(int i=1;i<=n;i++) {
        idx++;
        arr[idx].x=i;
        arr[idx].type=1;
        cin>>arr[idx].y;
        num.push_back(arr[idx].y);
    }
    for(int i=1;i<=m;i++) {
        char op;
        cin>>op;
        if(op=='Q') {
            idx++;
            arr[idx].type=0;
            arr[idx].id=++tot;
            cin>>arr[idx].x>>arr[idx].y>>arr[idx].z;
        }
        else {
            idx++;
            arr[idx].type=-1;
            cin>>arr[idx].x;
            idx++;
            arr[idx].type=1;
            arr[idx].x=arr[idx-1].x;
            cin>>arr[idx].y;
            num.push_back(arr[idx].y);
        }
    }

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=idx;i++) 
        if(arr[i].type==1) arr[i].y=
            lower_bound(num.begin(),num.end(),arr[i].y)-num.begin()+1;
    
    for(int i=1;i<=idx;i++)
        if(arr[i].type==-1) arr[i].y=last[arr[i].x];
        else if(arr[i].type==1) last[arr[i].x]=arr[i].y;

    tr.sz=n;
    solve(1, num.size(), 1, idx);
    for(int i=1;i<=tot;i++) cout<<num[ans[i]-1]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}