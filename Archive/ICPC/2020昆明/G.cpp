#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int,int> PII;
const int N=510,D=370,M=16,W=10010;

struct FRIEND {
    int d,c,v;
    bool operator< (const FRIEND &x) const {return d<x.d;}
} fri[N];
PII gift[M];
int dp[N][D][M],dp2[M][M][W];

int month[]={0,31,59,90,120,151,181,212,243,273,304,334,365};
int leap[]={1992,1996,2000,2004,2008};
inline bool check(int y,int m,int d){
    for(int i=0;i<5;i++) 
        if(y==leap[i]) return m==2&&d==29;
    return 0;
}

inline void read(int &y,int &m,int &d){
    string date;
    cin>>date;
    y=m=d=0;
    d+=(date.back()-'0')*1,date.pop_back();
    d+=(date.back()-'0')*10,date.pop_back();
    date.pop_back();
    m+=(date.back()-'0')*1,date.pop_back();
    m+=(date.back()-'0')*10,date.pop_back();
    date.pop_back();
    y+=(date.back()-'0')*1,date.pop_back();
    y+=(date.back()-'0')*10,date.pop_back();
    y+=(date.back()-'0')*100,date.pop_back();
    y+=(date.back()-'0')*1000,date.pop_back();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n,m,w;
        cin>>n>>m>>w;
        for(int i=1;i<=n;i++) {
            int y,m,d,c,v;
            read(y,m,d);
            cin>>c>>v;
            if(check(y,m,d)) i--,n--;
            else fri[i]={month[m-1]+d,c,v};
        }
        sort(fri+1,fri+1+n);
        for(int i=1;i<=m;i++) cin>>gift[i].first>>gift[i].second;

        memset(dp2,0,sizeof dp2);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=i;j++)
                for(int k=1;k<=w;k++){
                    dp2[i][j][k]=max({dp2[i-1][j][k],dp2[i][j-1][k],dp2[i][j][k-1]});
                    if(k>=gift[i].first) 
                        dp2[i][j][k]=max(dp2[i][j][k],dp2[i-1][j-1][k-gift[i].first]+gift[i].second);
                }

        for(int i=0;i<=n;i++) for(int j=0;j<=fri[n].d;j++) 
            memset(dp[i][j],0xcf,sizeof (int)*(m+1));
        for(int i=0;i<=n;i++) dp[i][0][0]=0;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=fri[i].d;j++)
                for(int k=0;k<=min(m,i);k++){
                    dp[i][j][k]=max(dp[i][j-1][k],dp[i-1][j][k]);
                    if(j>=fri[i].c) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-fri[i].c][k]+fri[i].v);
                    if(k) dp[i][j][k]=max({dp[i][j][k],dp[i-1][j][k-1],dp[i][j][k-1]});
                }
        int ans=0;
        for(int i=0;i<=m;i++) ans=max(ans,dp[n][fri[n].d][i]+dp2[m][i][w]);
        cout<<ans<<endl;
    }
    return 0;
}

/*
//dp2[i][j][k]=i位置，选了了不超过j个，代价不超过k

//1. make cake
//2. buy gift
//3. do nothing
//dp[i][j][k]=i位置，花费天数不超过j，买礼物不超过k，的最大值

dp[i][j][k] <- dp[i][j-1][k]//花费不超过j天
            <- dp[i][j][k-1]//买礼物不超过k
            <- dp[i-1][j-cake][k]+v//决策1
            <- dp[i-1][j][k-1]//决策2
            <- dp[i-1][j][k]//决策3
*/