#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=5e3+10,mod=1e9+7;
int dp[N][N],pre[N];

LL get_dp(string str){
    int n=str.size()-1;

    vector<int> lim(1);
    int left=0,right=0;

    pre[0]=0;
    for(int i=1;i<=n;i++)
        if(str[i]=='(') left++,pre[i]=pre[i-1]+1;
        else right++,pre[i]=pre[i-1]-1;

    for(int i=n-1;i>=1;i--)
        pre[i]=min(pre[i+1],pre[i]);

    int maxx=left-right;
    for(int i=1;i<=n;i++) 
        if(str[i]=='(')
            lim.push_back(pre[i]);
    n=lim.size()-1;

    memset(dp,0,sizeof dp);
    for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=n;i++)   
        for(int j=1;j<=lim[i];j++)
            dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;

    return dp[n][maxx];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int n=s.size();
    s=" "+s;
    int idx=-1,minn=0;

    for(int i=1;i<=n;i++){
        if(s[i]=='(') pre[i]=pre[i-1]+1;
        else{
            pre[i]=pre[i-1]-1;
            if(pre[i]<minn) idx=i;
            minn=min(minn,pre[i]);
        }
    }

    if(idx==-1) cout<<get_dp(s);
    else if(idx==n){
        string str=" ";
        for(int i=n;i>=1;i--) 
            str.push_back(s[i]=='('?')':'(');
        cout<<get_dp(str);
    }
    else{
        string str=" ";
        for(int i=idx;i>=1;i--)
            str.push_back(s[i]=='('?')':'(');
        LL res1=get_dp(str);

        str=" ";
        for(int i=idx+1;i<=n;i++)
            str.push_back(s[i]);
        LL res2=get_dp(str);

        cout<<res1*res2%mod;
    }
    return 0;
}