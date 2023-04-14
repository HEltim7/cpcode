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
            for(int k=0;k<=M;k++)
                if(abs(j-k)>=2)
                    dp[i][j]+=dp[i-1][k];
}

int cal(int x) {
    vector<int> num;
    while(x) num.push_back(x%10),x/=10;
    reverse(num.begin(),num.end());
    int last=-1,ans=0,len=num.size();
    for(int i=1;i<len;i++) for(int j=1;j<=M;j++) ans+=dp[i][j];
    for(int cur:num) {
        for(int i=last==-1?1:0;i<cur;i++) 
            if(abs(last-i)>=2) ans+=dp[len][i];
        if(abs(cur-last)<2) break;
        last=cur,len--;
    }
    return ans;
}

void solve() {
    init();
    int l,r;
    cin>>l>>r;
    cout<<cal(r+1)-cal(l);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}