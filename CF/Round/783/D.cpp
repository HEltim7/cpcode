#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;

const int N=5e5+10;
int dp[N],tr[N];
int rk[N],arr[N];

inline void add(int pos,int val){
    while(pos<N) tr[pos]=max(tr[pos],val),pos+=lowbit(pos);
}

inline int query(int pos){
    int res=-1e9;
    while(pos) res=max(res,tr[pos]),pos-=lowbit(pos);
    return res;
}

void solve(){
    int n;
    cin>>n;
    memset(dp,0xcf,sizeof (int)*(n+1));
    memset(tr,0xcf,sizeof (int)*(n+1));
    vector<pair<LL,int>> v;
    arr[0]=dp[0]=0;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=0;i<=n;i++) {
        LL last=v.empty()?0:v.back().first;
        v.emplace_back(arr[i]+last,i);
    }
    sort(v.begin(),v.end());
    for(int i=0,idx=0;i<v.size();i++){
        idx+=(i==0||v[i].first>v[i-1].first?1:0);
        rk[v[i].second]=idx;
    }
    add(rk[0],0);

    for(int i=1;i<=n;i++){
        if(arr[i]<0) dp[i]=dp[i-1]-1;
        else if(arr[i]==0) dp[i]=dp[i-1];
        dp[i]=max(dp[i],i+query(rk[i]-1));
        add(rk[i],dp[i]-i);
    }
    cout<<dp[n]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}