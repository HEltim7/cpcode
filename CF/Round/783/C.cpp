#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=5e3+10;
LL arr[N];
LL sum[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    LL ans=1e18;
    for(int i=1;i<=n;i++){
        LL res=0;
        memset(sum,0,sizeof sum);
        for(int j=i+1;j<=n;j++){
            LL t=sum[j-1]/arr[j]+1;
            res+=t;
            sum[j]=arr[j]*t;
        }
        for(int j=i-1;j>=1;j--){
            LL t=sum[j+1]/arr[j]+1;
            res+=t;
            sum[j]=arr[j]*t;
        }
        ans=min(ans,res);
    }
    cout<<ans;
    return 0;
}