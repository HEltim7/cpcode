#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e6+10,M=1e8+10,INF=0x3f3f3f3f;
unordered_map<int,int> loc;
vector<int> num;

struct NODE {
    int lch,rch;
    LL sum;
} tr[M];
int root[N],idx;

LL __query(int x,int l,int r,int val){
    if(val<=0) return 0;
    if(r<=val) return tr[x].sum;
    int mid=l+r>>1;
    LL res=__query(tr[x].lch,l,mid,val);
    if(val>mid) res+=__query(tr[x].rch,mid+1,r,val);
    return res;
}

int add(int pre,int l,int r,int val){
    int cur=++idx;
    tr[cur]=tr[pre];
    if(l!=r) {
        int mid=l+r>>1;
        if(val<=mid) tr[cur].lch=add(tr[pre].lch,l,mid,val);
        else tr[cur].rch=add(tr[cur].rch,mid+1,r,val);
    }
    tr[cur].sum+=num[val];
    return cur;
}

int build(int l,int r){
    int root=++idx;
    if(l==r) return root;
    int mid=l+r>>1;
    tr[root]={build(l,mid),build(mid+1,r)};
    return root;
}

inline LL get(int l,int r,int val){
    return __query(root[r],1,loc.size(),val)-__query(root[l-1],1,loc.size(),val);
}

LL query(int l,int r){
    LL pre=0;
    LL maxx=get(l,r,loc.size());
    LL last=0;
    while(pre<maxx){
        int a=upper_bound(num.begin(),num.end(),pre+1)-num.begin()-1;
        if(num[a]>pre+1) return pre+1;
        LL res=get(l,r,a);
        if(res==last) return res+1;
        pre=last=res;
    }
    return maxx+1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,Q;
    int read[N];
    cin>>n>>Q;
    num.push_back(0);
    num.push_back(INF);
    for(int i=1;i<=n;i++){
        cin>>read[i];
        num.push_back(read[i]);
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<num.size();i++) loc.emplace(num[i],i);

    root[0]=build(1,loc.size());
    for(int i=1;i<=n;i++) 
        root[i]=add(root[i-1],1,loc.size(),loc[read[i]]);

    LL last=0;
    for(int i=1;i<=Q;i++){
        int a,b,l,r;
        cin>>a>>b;
        l=min((a+last)%n+1,(b+last)%n+1);
        r=max((a+last)%n+1,(b+last)%n+1);
        cout<<(last=query(l,r))<<endl;
    }
    return 0;
}