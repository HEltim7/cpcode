#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e3+10,mod=1e9+7;
LL dp[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    vector<int> melon,ans;
    int n,m;
    cin>>m;
    dp[0]=1;
    for(int i=1;i<=m;i++){
        int in;
        cin>>in;
        in=(in-dp[i]+mod)%mod;
        for(int j=1;j<=in;j++) 
            ans.push_back(i*2),melon.push_back(i*2);
        for(int x:melon){
            for(int j=m;j>=x/2;j--){
                if(j>=x) dp[j]=(dp[j]+dp[j-x])%mod;
                dp[j]=(dp[j]+dp[j-x/2])%mod;
            }
        }
        melon.clear();
    }
    cout<<ans.size()<<endl;
    for(int x:ans) cout<<x<<' ';
    return 0;
}