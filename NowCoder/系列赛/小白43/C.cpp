#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

#define endl '\n'
const int N=10;
int stick[N];
int type[N];
double ans;
int n;

void dfs(int idx){
    if(idx==n+1){
        int a1,a2,a3,cnt=n;
        a1=a2=a3=0;
        for(int i=1;i<=n;i++)
            if(type[i]==1) a1+=stick[i];
            else if(type[i]==2) a2+=stick[i];
            else if(type[i]==3) a3+=stick[i];
            else cnt--;
        if(cnt<3) return;
        if(a1+a2>a3&&a2+a3>a1&&a1+a3>a2){
            double p=(a1+a2+a3)/2;
            double res=sqrt(p*(p-a1)*(p-a2)*(p-a3));
            ans=max(ans,res);
        }
        return;
    }
    for(int i=0;i<=3;i++){
        type[idx]=i;
        dfs(idx+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>stick[i];
    dfs(1);
    if(ans>0) cout<<fixed<<setprecision(1)<<ans;
    else cout<<-1;
    return 0;
}