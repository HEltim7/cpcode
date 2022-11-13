#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=20,M=1<<19;
int arr[N][N],id[N][N],dp[M];
bool ingrid[N][N];
vector<int> bits[N];
vector<pair<int,int>> grid;
vector<tuple<int,int,int,int,int,int>> trans;

void init() {
    int idx=0;
    for(int i=1;i<=3;i++) grid.emplace_back(1,i),id[1][i]=idx++;
    for(int i=1;i<=4;i++) grid.emplace_back(2,i),id[2][i]=idx++;
    for(int i=1;i<=5;i++) grid.emplace_back(3,i),id[3][i]=idx++;
    for(int i=2;i<=5;i++) grid.emplace_back(4,i),id[4][i]=idx++;
    for(int i=3;i<=5;i++) grid.emplace_back(5,i),id[5][i]=idx++;
    for(auto [x,y]:grid) cin>>arr[x][y];
    for(auto [x,y]:grid) ingrid[x][y]=1;

    for(int i=0;i<M;i++) bits[__builtin_popcount(i)].push_back(i);
    int mvr[]={-1,-1,0,0,1,1};
    int mvc[]={-1,0,-1,1,0,1};

    for(auto [x,y]:grid) {
        for(int i=0;i<6;i++) {
            int r=x+mvr[i];
            int c=y+mvc[i];
            int p=r+mvr[i];
            int q=c+mvc[i];
            if(r>=1&&c>=1&&p>=1&&q>=1&&ingrid[r][c]&&ingrid[p][q])
                trans.emplace_back(x,y,r,c,p,q);
        }
    }
    
    for(int bit=0;bit<=19;bit++) {
        for(int st:bits[bit]) {
            auto get=[&](int x,int y) {
                return st&(1<<id[x][y]);
            };

            for(auto [x,y,r,c,p,q]:trans) {
                if(get(x,y)&&!get(r,c)&&!get(p,q)) {
                    int ne=(1<<id[r][c])|(1<<id[p][q])|st^(1<<id[x][y]);
                    dp[ne]=max(dp[ne],dp[st]+arr[r][c]);
                }
            }
            for(int i=0;i<19;i++) dp[1<<i|st]=max(dp[1<<i|st],dp[st]);
        }
    }
}

void solve() {
    int st=0;
    for(auto [x,y]:grid) {
        char in;
        cin>>in;
        if(in=='#') st|=1<<id[x][y];
    }
    cout<<dp[st]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}