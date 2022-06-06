#include<iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
const int N=5e3+10;
int dp[N][N];//表示i到j区间子串是否可行
int ans;

inline bool check(char a,char b){
    return a-b==32||b-a==32;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string str;
    cin>>str;
    str=' '+str;
    for(int r=1;r<str.length();r++){//枚举右端点
        for(int l=1;l<r;l++){//枚举左端点
            if((r-l)%2==0) continue;
            if(check(str[r],str[l])){
                if(r-l==1) dp[l][r]=2;
                else if(dp[l+1][r-1]) dp[l][r]=dp[l+1][r-1]+2;
                ans=max(ans,dp[l][r]);
            }
        }
    }
    cout<<ans;
}