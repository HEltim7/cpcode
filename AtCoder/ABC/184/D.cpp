#include<vector>
#include<iostream>
#include<algorithm>
#include<tuple>
#include<iomanip>
using namespace std;

#define endl '\n'
using LL=long long;
using TIII=tuple<int,int,int>;
const int N=101;
double dp[N*N*N];

inline int get(int a,int b,int c){
    return a*N*N+b*N+c;
}

void dfs(int a,int b,int c,int step){
    if(a==100||b==100||c==100) dp[get(a,b,c)]=step;
    else if(dp[get(a,b,c)]>0) return;
    else{
        dfs(a+1,b,c,step+1);
        dfs(a,b+1,c,step+1);
        dfs(a,b,c+1,step+1);

        dp[get(a,b,c)]=(
            dp[get(a+1,b,c)]*a+
            dp[get(a,b+1,c)]*b+
            dp[get(a,b,c+1)]*c
        )/(a+b+c);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int a,b,c;
    cin>>a>>b>>c;
    dfs(a,b,c,0);
    cout<<fixed<<setprecision(9)<<dp[get(a,b,c)];
    return 0;
}