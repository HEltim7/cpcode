#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
const int N=4e5+10,mod=1e9+7;
using PII=pair<int,int>;
PII dp[N];
PII in[N];
int arr[N];
int n;

void add(int pos,PII val) {
    while(pos<=n) {
        if(dp[pos].first<val.first) dp[pos]=val;
        else if(dp[pos].first==val.first) 
            dp[pos].second=(dp[pos].second+val.second)%mod;
        pos+=lowbit(pos);
    }
}

PII query(int pos) {
    PII res={0,1};
    while(pos) {
        if(dp[pos].first>res.first) res=dp[pos];
        else if(dp[pos].first==res.first) 
            res.second=(res.second+dp[pos].second)%mod;
        pos-=lowbit(pos);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>in[i].first,in[i].second=i;
    sort(in+1,in+1+n);
    int idx=0;
    in[0].first=-1e9;
    for(int i=1;i<=n;i++) 
        if(in[i].first!=in[i-1].first) arr[in[i].second]=++idx;
        else arr[in[i].second]=idx;
    for(int i=1;i<=n;i++) {
        auto pre=query(arr[i]-1);
        pre.first++;
        add(arr[i],pre);
    }
    cout<<query(idx).second;
    return 0;
}