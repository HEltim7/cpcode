#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int n,ans;
int a[100],b[100];
int idxa,idxb;
int matrix[100][100];

void dfs(int deep){
    if(deep>n){
        if(idxb==0||idxa==0) return;
        int res=0;
        for(int i=1;i<=idxa;i++) for(int j=1;j<=idxa;j++) res+=matrix[a[i]][a[j]];
        for(int i=1;i<=idxb;i++) for(int j=1;j<=idxb;j++) res+=matrix[a[i]][a[j]];
        ans=max(ans,res);
        return ;
    }
    a[++idxa]=deep;
    dfs(deep+1);
    a[idxa--]=0;
    b[++idxb]=deep;
    dfs(deep+1);
    b[idxb--]=0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>matrix[i][j];
    dfs(1);
    cout<<ans;
}