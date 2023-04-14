#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

using LL=long long;
using PII=pair<int,int>;
#define endl '\n'
#define debug(x) \
    cerr<<string("[")+string(__func__)+string(" ")+to_string(__LINE__)+string("] ")\
    <<string(#x)+string(" = ")<<x<<endl;
constexpr int N=5e5+10,M=26*2+5;
int dp[N][M];
bool mark[M];
PII pos[M];

void solve() {
    string s,t;
    cin>>s>>t;
    s=" "+s;
    t=" "+t;
    for(int i=1;i<t.size();i++) {
        int c=t[i]-'a';
        if(!mark[c]) mark[c]=1,pos[c]={i,i};
        else pos[c].second=i;
    }

    vector<int> num;
    for(int i=0;i<26;i++) 
        if(pos[i].first) {
            num.push_back(pos[i].first);
            num.push_back(pos[i].second);
        }

    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=0;i<26;i++)
        if(pos[i].first) {
            pos[i].first=lower_bound(num.begin(),num.end(),pos[i].first)-num.begin()+1;
            pos[i].second=lower_bound(num.begin(),num.end(),pos[i].second)-num.begin()+1;
        }

    int cnt=num.size();
    for(int i=1;i<s.size();i++) {
        int c=s[i]-'a';
        for(int j=cnt;j>=1;j--) {
            if(!mark[c]) dp[i][j]=dp[i-1][j]+1;
            else {
                dp[i][j]=dp[i-1][j];
                if(j<=pos[c].first) dp[i][j]=max(dp[i][j],dp[i-1][pos[c].second]+1);
            }
            dp[i][j]=max(dp[i][j],dp[i][j+1]);
        }
    }
    
    cout<<dp[s.size()-1][1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}