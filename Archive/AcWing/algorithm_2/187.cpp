#include<iostream>
using namespace std;

#define endl '\n'

const int N=55;
int rocket[N];
int up[N],down[N];
int n;
int ans;

void dfs(int deep,int uplen,int downlen){
    if(uplen+downlen>=ans) return;//剪枝
    if(deep>n){
        ans=uplen+downlen;
        return;
    }
    //当前导弹加入上升序列
    int i=0;
    while(i<=uplen) if(up[++i]<rocket[deep]) break;
    int bak=up[i];
    up[i]=rocket[deep];
    if(i>uplen) dfs(deep+1,uplen+1,downlen);
    else dfs(deep+1,uplen,downlen);
    up[i]=bak;

    //当前导弹加入下降序列
    i=0;
    while(i<=downlen) if(down[++i]>rocket[deep]) break;
    bak=down[i];
    down[i]=rocket[deep];
    if(i>downlen) dfs(deep+1,uplen,downlen+1);
    else dfs(deep+1,uplen,downlen);
    down[i]=bak;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(cin>>n&&n){
        ans=n;
        for(int i=1;i<=n;i++) cin>>rocket[i];
        dfs(1,0,0);
        cout<<ans<<endl;
    }
    return 0;
}