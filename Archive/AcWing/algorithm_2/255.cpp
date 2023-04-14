#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<PII> VII;
const int N=2e5+10,INF=0x3f3f3f3f;

struct NODE{
    int l,r,cnt;
}tr[N*20];
int num[N],val[N],root[N];
int idx;


int build(int l,int r){
    int root=++idx;
    if(l==r) return root;
    int mid=l+r>>1;
    tr[root]={build(l,mid),build(mid+1,r)};
    return root;
}

int add(int pre,int l,int r,int x){
    int cur=++idx;
    tr[cur]=tr[pre];//clone the prev node
    if(l==r){
        tr[cur].cnt++;
        return cur;
    }
    int mid=l+r>>1;
    if(x<=mid) tr[cur].l=add(tr[pre].l,l,mid,x);
    else tr[cur].r=add(tr[pre].r,mid+1,r,x);
    // tr[cur].cnt=tr[tr[cur].l].cnt+tr[tr[cur].r].cnt;
    tr[cur].cnt++;
    return cur;
}

int query(int pre,int cur,int l,int r,int k){
    if(l==r) return l;
    int cnt=tr[tr[cur].l].cnt-tr[tr[pre].l].cnt;
    int mid=l+r>>1;
    if(cnt>=k) return query(tr[pre].l,tr[cur].l,l,mid,k);
    else return query(tr[pre].r,tr[cur].r,mid+1,r,k-cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    VII arr;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        arr.emplace_back(in,i);
    }
    sort(arr.begin(),arr.end());
    int cnt=0;
    for(int i=0;i<arr.size();i++)
        if(i&&arr[i].first==arr[i-1].first) num[arr[i].second]=cnt;
        else num[arr[i].second]=++cnt,val[cnt]=arr[i].first;
    
    root[0]=build(1,cnt);
    for(int i=1;i<=n;i++) 
        root[i]=add(root[i-1],1,cnt,num[i]);

    for(int i=1;i<=m;i++){
        int l,r,k;
        cin>>l>>r>>k;
        cout<<val[query(root[l-1],root[r],1,cnt,k)]<<endl;
    }
    return 0;
}