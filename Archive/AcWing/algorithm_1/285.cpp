#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=6e3+10;
int e[N],ne[N],h[N],idx;
int happy[N];
int dp[N][2];
bool mark[N][2];

void add(int a,int b){
    e[++idx]=b,ne[idx]=h[a],h[a]=idx;
}

int getdp(int id,int state){
    if(!id) return 0;
    if(mark[id][state]) return dp[id][state];
    if(state) dp[id][state]+=happy[id];
    for(int i=h[id];i;i=ne[i]){
        int j=e[i];
        if(state) dp[id][state]+=getdp(j,0);
        else dp[id][state]+=max(getdp(j,1),getdp(j,0));
    }
    mark[id][state]=1;
    return dp[id][state];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>happy[i];
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        add(b,a);
    }
    
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,max(getdp(i,1),getdp(i,0)));
    cout<<ans;
    return 0;
}