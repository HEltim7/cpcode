#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<tuple>
using namespace std;

#define endl '\n'
using LL=long long;
using TIII=tuple<int,int,int>;
using PII=pair<int,int>;
const int N=2e5+10;
int arr[N],cnt[N];
int n,k,minn,maxx;

TIII get_range(int len) {
    int x,y,val=-1;
    for(int l=minn,r=minn+len;r<=maxx;l++,r++) 
        if(cnt[r]-cnt[l-1]>val) x=l,y=r,val=cnt[r]-cnt[l-1];
    return make_tuple(x,y,val);
}

bool check(int len) {
    auto [x,y,val]=get_range(len);
    return val>=cnt[maxx]-val+k;
}

void solve() {
    cin>>n>>k;
    minn=N,maxx=0;
    memset(cnt,0,sizeof (int)*(n+1));
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        minn=min(minn,arr[i]);
        maxx=max(maxx,arr[i]);
        cnt[arr[i]]++;
    }
    for(int i=minn;i<=maxx;i++) cnt[i]+=cnt[i-1];
    int l=0,r=maxx-minn;
    while(l<r) {
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    auto [x,y,val]=get_range(l);
    cout<<x<<' '<<y<<endl;
    vector<int> ans(1,0);
    for(int i=1,sum=0;i<=n;i++) {
        if(arr[i]>=x&&arr[i]<=y) sum++;
        else sum--;
        if(sum>0&&k>1) sum=0,ans.push_back(i),k--;
    }
    ans.push_back(n);
    for(int i=1;i<ans.size();i++) 
        cout<<ans[i-1]+1<<' '<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}