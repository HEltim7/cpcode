#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<double,int> PDI;
typedef pair<int,int> PII;
const int N=2e3+10;

priority_queue<PDI,vector<PDI>,greater<PDI>> heap[N];
double dis[N];
bool mark[N];
const double PI=acos(-1);

inline double cal(LL r1,LL c1,LL r2,LL c2){
    return sqrt(abs(r1-r2)*abs(r1-r2)+abs(c1-c2)*abs(c1-c2));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    PII read[N];
    for(int i=1;i<=n;i++) cin>>read[i].first>>read[i].second;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) heap[i].emplace
                (cal(read[i].first,read[i].second,read[j].first,read[j].second),j);
    int cnt=n;
    while(cnt){
        int a,b;
        double dist=4e9;
        for(int i=1;i<=n;i++){
            if(heap[i].empty()) continue;
            auto [d,id]=heap[i].top();
            if(mark[id]) {
                heap[i].pop();
                i--;
                continue;
            }
            if(mark[i]) d-=dis[i];
            else d/=2;
            if(d<dist) dist=d,a=i,b=id;
        }
        double d=cal(read[a].first,read[a].second,read[b].first,read[b].second);
        if(mark[a]){
            dis[b]=d-dis[a];
            mark[b]=1;
            cnt--;
        }
        else{
            dis[a]=dis[b]=d/2;
            mark[a]=mark[b]=1;
            cnt-=2;
        }
    }
    double ans=0;
    for(int i=1;i<=n;i++) ans+=PI*dis[i]*dis[i];
    cout<<fixed<<setprecision(16)<<ans<<endl;
    // for(int i=1;i<=n;i++) cout<<i<<' '<<dis[i]<<endl;
    return 0;
}