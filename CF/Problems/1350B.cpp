#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
int dp[N],s[N];

void get(int x,vector<int> &res){
    res.push_back(1);
    int t=x;
    for(int i=2;i<=x/i;i++){
        if(x%i==0){
            res.push_back(i);
            res.push_back(x/i);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>s[i];
        for(int i=1;i<=n;i++){
            vector<int> cur;
            get(i,cur);
            dp[i]=1;
            for(auto x:cur)
                if(s[i]>s[x]) dp[i]=max(dp[i],dp[x]+1);
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}