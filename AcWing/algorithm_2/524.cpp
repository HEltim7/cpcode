#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;

#define x first
#define y second
#define endl '\n'

typedef pair<double,double> PDD;
typedef pair<int,int> PII;
const double eps=1e-8;
const int N=20;
PDD point[N];
int dp[1<<18];//状态为i的最小值
int state[N][N];//选中i点和j点所确定的抛物线的点覆盖状态
int n;

bool equ(double a,double b){
    return fabs(a-b)<eps;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int m,t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>point[i].x>>point[i].y;
        if(n==1){
            cout<<1<<endl;
            continue;
        }

        memset(state,0,sizeof state);
        vector<PII> line[N];//可以覆盖该点的抛物线
        //初始化每条合法抛物线可以得到的状态
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                double a,b;//y=ax+b
                if(equ(point[i].x,point[j].x)) continue;//斜率不存在
                a=(point[i].y/point[i].x-point[j].y/point[j].x)/(point[i].x-point[j].x);
                b=point[i].y/point[i].x-a*point[i].x;
                if(a>eps) continue;//抛物线开口向上
                if(equ(point[i].y*point[j].x,point[i].x*point[j].y)) continue;//直线
                //判断每个点是否被此抛物线覆盖
                for(int k=0;k<n;k++){
                    if(equ(point[k].y,a*pow(point[k].x,2)+b*point[k].x)){
                        state[i][j]+=1<<k;//已覆盖
                        line[k].push_back({i,j});
                    }
                }
            }
        }

        memset(dp,0x3f,sizeof dp);
        dp[0]=0;
        for(int i=0;i+1<1<<n;i++){//枚举所有状态
            for(int j=0;j<n;j++){//枚举所有点
                if((i>>j&1)==0){//当前点未覆盖
                    if(line[j].size())
                        for(PII k:line[j]){
                            int s=state[k.first][k.second];
                            dp[i|s]=min(dp[i|s],dp[i]+1);
                        }
                    else dp[i|1<<j]=min(dp[i|1<<j],dp[i]+1);//特判没有任何经过两点的抛物线满足
                }
            }
        }
        cout<<dp[(1<<n)-1]<<endl;
    }
    return 0;
}