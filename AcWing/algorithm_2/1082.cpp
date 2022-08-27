#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=32,M=9;
int dp[N+1][M+1];

void init() {
    for(int i=0;i<=M;i++) dp[1][i]=1;
    for(int i=2;i<=N;i++)
        for(int j=0;j<=M;j++)
            for(int k=j;k<=M;k++)
                dp[i][j]+=dp[i-1][k];
}

int cal(unsigned int x) {
    vector<int> num;
    while(x) num.push_back(x%10),x/=10;
    reverse(num.begin(),num.end());
    int last=1,ans=0,len=num.size();
    for(int i=1;i<len;i++) for(int j=1;j<=M;j++) ans+=dp[i][j];
    for(int cur:num) {
        for(int i=last;i<cur;i++) ans+=dp[len][i];
        if(cur<last) break;
        last=cur,len--;
    }
    return ans;
}

void solve() {
    init();
    unsigned int l,r;
    while(cin>>l>>r) cout<<cal(r+1)-cal(l)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}