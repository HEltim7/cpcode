#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using VI=vector<int>;
constexpr int N=22;
int grid[N][N];
VI cnt[N][N];
VI pre[N],suf[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)   
            cin>>grid[i][j];
    cnt[1][1].push_back(grid[1][1]);
    cnt[n][n].push_back(grid[n][n]);

    for(int i=1;i<=n;i++)
        for(int j=1;i+j<=n;j++) {
            int r,c;
            r=i+1,c=j;
            if(r<=n) {
                if(i+j==n) {
                    for(auto x:cnt[i][j])
                        pre[r].push_back(x);
                }
                else {
                    for(auto x:cnt[i][j])
                        cnt[r][c].push_back(x^grid[r][c]);
                }
            }
            r=i,c=j+1;
            if(c<=n) {
                if(i+j==n) {
                    for(auto x:cnt[i][j])
                        pre[r].push_back(x);
                }
                else {
                    for(auto x:cnt[i][j])
                        cnt[r][c].push_back(x^grid[r][c]);
                }
            }
        }

    for(int i=n;i>=1;i--)
        for(int j=n;i+j>=n+2;j--) {
            int r,c;
            r=i-1,c=j;
            if(r>=1) {
                if(i+j==n+2) {
                    for(auto x:cnt[i][j])
                        suf[r].push_back(x);
                }
                else {
                    for(auto x:cnt[i][j])
                        cnt[r][c].push_back(x^grid[r][c]);
                }
            }
            r=i,c=j-1;
            if(c>=1) {
                if(i+j==n+2) {
                    for(auto x:cnt[i][j])
                        suf[r].push_back(x);
                }
                else {
                    for(auto x:cnt[i][j])
                        cnt[r][c].push_back(x^grid[r][c]);
                }
            }
        }

    LL ans=0;
    for(int i=1;i<=n;i++) {
        for(auto &x:pre[i]) x^=grid[i][n-i+1];
        sort(pre[i].begin(),pre[i].end());
        sort(suf[i].begin(),suf[i].end());
        auto count=[](VI &x) {
            int res=0,v=x.back();
            while(x.size()&&x.back()==v) res++,x.pop_back();
            return res;
        };
        while(pre[i].size()&&suf[i].size()) {
            if(pre[i].back()==suf[i].back()) ans+=count(pre[i])*1LL*count(suf[i]);
            else if(pre[i].back()<suf[i].back()) suf[i].pop_back();
            else pre[i].pop_back();
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}