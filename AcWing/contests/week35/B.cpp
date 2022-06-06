#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
LL a[5],ans;
bool mark[5];
char op[5];

void dfs(int deep){
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            if(mark[i]||mark[j]||i==j) continue;
            LL now;
            if(op[deep]=='*')
                now=a[i]*a[j];
            else now=a[i]+a[j];
            if(deep==3){
                ans=min(ans,now);
                continue;
            }
            mark[i]=1;
            LL tmp=a[j];
            a[j]=now;
            dfs(deep+1);
            a[j]=tmp;
            mark[i]=0;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ans=1e18;
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    cin>>op[1]>>op[2]>>op[3];
    dfs(1);
    cout<<ans;
    return 0;
}