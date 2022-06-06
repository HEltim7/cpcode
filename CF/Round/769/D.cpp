#include<vector>
#include<iostream>
#include<algorithm>
#include<numeric>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N],dp[N][30],ans[N];
int n;

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

void init(){
    for(int i=1;i<=n;i++) dp[i][0]=arr[i];
    for(int k=1;k<30;k++)
        for(int i=1;i+(1<<k)-1<=n;i++)
            dp[i][k]=gcd(dp[i][k-1],dp[i+(1<<(k-1))][k-1]);
}

inline int get(int l,int r){
    if(l==r) return arr[l];
    int len=r-l+1;
    int k=0;
    for(int i=29;i>=0;i--)
        if((1<<i)<len)
            return gcd(dp[l][i],dp[r-(1<<i)+1][i]);
    assert(false);
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    init();

    for(int i=1;i<=n;i++) debug(dp[i]);

    vector<pair<int,int>> segs;
    for(int i=1;i<=n;i++){
        int l=i,r=n;
        while(l<r){
            int mid=l+r+1>>1;
            debug(i,l,mid,r,get(i,mid));
            if(get(i,mid)>=(mid-i+1)) l=mid;
            else r=mid-1;
        }
        if(get(i,l)==l-i+1) segs.emplace_back(i,l);
    }

    debug(segs);

    sort(segs.begin(),segs.end(),[](pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    });
    
    int idx=0;
    for(auto [l,r]:segs){
        if(l<=idx) continue;
        ans[r]=1;
        idx=r;
    }
    for(int i=1,res=0;i<=n;i++) cout<<(res+=ans[i])<<' ';
    return 0;
}