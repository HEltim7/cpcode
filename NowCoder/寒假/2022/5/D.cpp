#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=110;
LL dp[N][N][2];//dp[i][j]=i位，最高位为j的数量，是否有1
vector<int> ne[20];

inline bool check(int x){
    if(x==1||x==0) return 0;
    for(int i=2;i<=x/i;i++)
        if(x%i==0) return 0;
    return 1;
}

inline void init(){
    for(int i=0;i<=9;i++) 
        for(int j=0;j<=9;j++)
            if(check(i+j)) ne[i].push_back(j);

    for(int i=0;i<=9;i++) 
        if(i==1) dp[1][i][1]=1;
        else dp[1][i][0]=1;
    for(int i=2;i<=10;i++) //枚举位数
        for(int j=0;j<=9;j++) //枚举最高位
            for(auto x:ne[j]) //枚举可行值
                if(j==1)
                    dp[i][j][1]+=dp[i-1][x][0]+dp[i-1][x][1];
                else dp[i][j][1]+=dp[i-1][x][1],
                     dp[i][j][0]+=dp[i-1][x][0];
}

//计算从1到n的数量
inline int getdp(LL n){
    if(n<1LL) return 0;
    if(n<10LL) return 1;
    vector<int> num;
    while(n){
        num.push_back(n%10);
        n/=10;
    }
    reverse(num.begin(),num.end());
    LL last=-1,res=0;
    bool one=0;
    for(int i=2;i<num.size();i++)
        for(int j=1;j<=9;j++)
            res+=dp[i][j][1];

    for(int i=0;i<num.size();i++){
        int x=num[i];
        int bit=num.size()-i;
        for(int j=(i==0?1:0);j<x;j++) 
            if(last==-1||check(last+j)){
                if(one) res+=dp[bit][j][1]+dp[bit][j][0];
                else res+=dp[bit][j][1];
            }
        if(last!=-1&&!check(last+x)) break;
        else last=x;
        if(x==1) one=1;
    }
    bool flag=one;
    for(int i=0;i<num.size()-1;i++)
        if(!check(num[i]+num[i+1])) flag=0;
    return res+1+flag;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init();
    LL l,r;
    cin>>l>>r;
    cout<<getdp(r)-getdp(l-1);
    return 0;
}