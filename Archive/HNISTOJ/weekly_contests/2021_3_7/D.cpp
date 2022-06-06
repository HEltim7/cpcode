#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
ll num[30],aim,ok=0;
bool res[23];

void output(){
    for(int i=1;i<=n;i++) if(res[i]) cout<<num[i]<<' ';
    cout<<endl;
    ok++;
}

void dfs(int now,ll sum){
    if(now==1){
        if(sum==aim){
            res[1]=0;
            output();
        }
        if(sum+num[1]==aim){
            res[1]=1;
            output();
        }
    }
    else{
        res[now]=0;
        dfs(now-1,sum);
        res[now]=1;
        dfs(now-1,sum+num[now]);
    }
    return;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    cin>>aim;
    sort(num+1,num+n+1);
    dfs(n,0);
    if(aim==0) ok--;
    cout<<ok;
    return 0;
}