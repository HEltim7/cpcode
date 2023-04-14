#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef vector<int> VI;
const int N=5e3+10;
int dp[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        VI lord[n+1],arr;
        for(int i=1;i<=n;i++){
            int in;
            cin>>in;
            if(arr.empty()||arr.size()&&in!=arr.back()) {
                arr.push_back(in);
                lord[in].push_back(arr.size()-1);
            }
        }

        for(int len=2;len<=arr.size();len++) 
            for(int l=0;l+len-1<arr.size();l++){ 
                dp[len][l]=dp[len-1][l+1]+1; 
                for(auto x:lord[arr[l]])
                    if(x-l>1&&x<=l+len-1)
                        dp[len][l]=min(dp[len][l],dp[x-l-1][l+1]+dp[len-(x-l)][x]+1);
            }
        cout<<dp[arr.size()][0]<<endl;
    }
    return 0;
}