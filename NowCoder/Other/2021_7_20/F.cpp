#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=1e4+10;
double dp[N];
// double prob[110][N];//储存可能性
struct taskdata
{
    int start;
    int end;
    double score;
    double prob[110];//每个pilot的可能性
} task[N];

struct pilot
{
    double res;
    int id;
} ans[110];//储存每个pilot最大score


int maxtime=1e4+1;//顺推1

bool cmp(taskdata a,taskdata b){
    return a.end<b.end;
}

bool cmp2(pilot a,pilot b){
    return a.res>b.res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t,p;
    cin>>t>>p;
    //每个时间顺推1,从1开始
    for(int i=1;i<=t;i++) cin>>task[i].start>>task[i].end>>task[i].score,task[i].start++,task[i].end++;
    for(int i=1;i<=p;i++) for(int j=1;j<=t;j++) cin>>task[j].prob[i];

    sort(task+1,task+1+t,cmp);//按结束时间排序task

    for(int i=1;i<=p;i++){//遍历所有时间
        memset(dp,0,sizeof dp);//遍历每个pilot
        int idx=1;//task指针
        for(int j=1;j<=maxtime;j++){
            dp[j]=dp[j-1];//不取
            while(task[idx].end==j){
                int taskstart=task[idx].start;
                dp[j]=max(dp[j],dp[taskstart]+task[idx].score*task[idx].prob[i]);
                idx++;
            }
        }
        ans[i].res=dp[maxtime];
        ans[i].id=i;
    }

    sort(ans+1,ans+1+p,cmp2);
    cout<<ans[1].id<<' '<<fixed<<setprecision(2)<<ans[1].res<<endl;
    cout<<ans[2].id<<' '<<fixed<<setprecision(2)<<ans[2].res<<endl;
    cout<<ans[3].id<<' '<<fixed<<setprecision(2)<<ans[3].res<<endl;
}