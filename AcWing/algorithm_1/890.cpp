#include<iostream>

using namespace std;

typedef long long ll;
const int N=20;
int n,m;
int p[N];
ll ans;
int neg=1;

void dfs(int deep,int now,int choice,ll res){
    if(now>deep){
        ans+=neg*n/res;
        return;
    }
    if(res>n||choice>m) return;
    for(int i=choice;i<=m;i++) dfs(deep,now+1,i+1,res*p[i]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>p[i];
    for(int i=1;i<=m;i++){
        dfs(i,1,1,1);
        neg*=-1;
    }
    cout<<ans;
    return 0;
}