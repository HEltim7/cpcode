#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

typedef vector<int> VI;
typedef long long LL;

const int N=55;
LL point[N];
VI dp[N][N];

VI add(VI &a,VI &b){
    if(a.size()<b.size()) return add(b,a);
    VI c;
    LL t=0;
    for(int i=0;i<a.size();i++){
        t+=a[i];
        if(i<b.size()) t+=b[i];
        c.push_back(t%10);
        t/=10;
    }
    if(t) c.push_back(t);
    return c;
}

VI mul(VI &a,LL b){
    VI c;
    LL t=0;
    for(int i=0;i<a.size()||t;i++){
        if(i<a.size()) t+=a[i]*b;
        c.push_back(t%10);
        t/=10;
    }
    while(c.size()>1&&c.back()==0) c.pop_back();
    return c;
}

bool cmp(VI &a,VI &b){
    if(a.size()>b.size()) return 1;
    else if(a.size()<b.size()) return 0;
    for(int i=a.size()-1;i>=0;i--) if(a[i]>b[i]) return 1; else if(a[i]<b[i]) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>point[i];
    
    for(int len=3;len<=n;len++){//枚举区间长度
        for(int l=1;l+len-1<=n;l++){//枚举左端点
            int r=l+len-1;//计算右端点
            for(int k=l+1;k<=r-1;k++){//枚举三角型左右端点对应的顶点
                LL tmp=point[l]*point[k];
                VI P,A,B,res;
                while(tmp) P.push_back(tmp%10),tmp/=10;
                A=add(dp[l][k],dp[k][r]);
                B=mul(P,point[r]);
                res=add(A,B);
                if(cmp(dp[l][r],res)||dp[l][r].empty()) dp[l][r]=res;
            }
        }
    }
    for(int i=dp[1][n].size()-1;i>=0;i--) cout<<dp[1][n][i];
    return 0;
}