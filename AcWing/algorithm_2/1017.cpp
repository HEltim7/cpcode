#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=110;
int dp[N];
int num[N];
int rev[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int K,n;
    cin>>K;
    while(K--){
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++) cin>>num[i],rev[n-i+1]=num[i];
        for(int i=1;i<=n;i++){
            dp[i]=1;
            for(int j=1;j<i;j++)
                if(num[i]<num[j])
                    dp[i]=max(dp[i],dp[j]+1);
        }
        for(int i=1;i<=n;i++) ans=max(ans,dp[i]);

        for(int i=1;i<=n;i++){
            dp[i]=1;
            for(int j=1;j<i;j++)
                if(rev[i]<rev[j])
                    dp[i]=max(dp[i],dp[j]+1);
        }        
        for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
        cout<<ans<<endl;
    }
    return 0;
}