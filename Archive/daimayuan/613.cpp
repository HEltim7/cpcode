#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=2e5+10,INF=0x3f3f3f3f;
int arr[N];

struct NODE {
    int l,r,min;
    int laze;
} tr[N*4];

inline void pushup(int x){
    tr[x].min=min(tr[x<<1].min,tr[x<<1|1].min);
}

inline void pushdn(int x){
    auto &p=tr[x],&l=tr[x<<1],&r=tr[x<<1|1];
    l.min+=p.laze,r.min+=p.laze;
    l.laze+=p.laze,r.laze+=p.laze;
    p.laze=0;
}

void modify(int x,int l,int r,int v){
    if(tr[x].l>=l&&tr[x].r<=r) tr[x].min+=v,tr[x].laze+=v;
    else{
        pushdn(x);
        int mid=tr[x].l+tr[x].r>>1;
        if(mid>=l) modify(x<<1,l,r,v);
        if(mid<r) modify(x<<1|1,l,r,v);
        pushup(x);
    }
}

int query(int x,int l,int r){
    if(tr[x].l>=l&&tr[x].r<=r) return tr[x].min;
    pushdn(x);
    int mid=tr[x].l+tr[x].r>>1;
    int res=INF;
    if(mid>=l) res=min(res,query(x<<1,l,r));
    if(mid<r) res=min(res,query(x<<1|1,l,r));
    return res;
}

void build(int x,int l,int r){
    tr[x]={l,r,0,0};
    if(l==r) return;
    else{
        int mid=l+r>>1;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        map<int,PII> mp;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
            mp.emplace(arr[i],make_pair(0,0));
        }

        bool ans=1;
        build(1,1,n);
        for(int i=1;i<=n;i++){
            auto it=mp.find(arr[i]);
            modify(1,it->second.second+1,i,1);
            if(it->second.first<it->second.second) 
                modify(1,it->second.first+1,it->second.second,-1);
            it->second.first=it->second.second,it->second.second=i;
            if(query(1,1,i)<=0){
                ans=0;
                break;
            }
        }
        cout<<string(ans?"non-boring":"boring")<<endl;
    }
    return 0;
}

/*

从前向后考虑，假设当前为i,前面已经处理完，即non-boring

当前区间必然引入一个数arr[i]，要使它boring,必然要从前面某个包含且仅包含一个arr[i]的后缀加上i得到

cnt[i] 表示从前面到当前点的区间，不同数的个数
当前下标为i,前一个出现当前数的下标为j,前两个出现的下标为k（找不到就是0） -> cnt[j+1->i]++; cnt[k+1,j]--; 同时把k更新为j,j更新为i
当有cnt归0时-> 结束

现在问题转化为，维护一种数据结构，支持快速区间修改，并支持快速查询0值

考虑差分树状数组，树状数组维护区间最小值，好像不行
线段树？节点维护最小值,区间加相当于最小值加1,区间减相当于最小值减1,似乎可行

*/