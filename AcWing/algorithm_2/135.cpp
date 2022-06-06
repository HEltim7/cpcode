#include<iostream>
using namespace std;

const int N=3e5+10;
const int INF=0x3f3f3f3f;
int prefix[N];
int ans=-INF;
int que[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,in;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>in,prefix[i]=prefix[i-1]+in;

    int h=0,t=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,prefix[i]-prefix[que[h]]);
        if(i-que[h]>=m) h++;
        while(prefix[i]<=prefix[que[t]]&&t>=h) t--;
        que[++t]=i;
    }
    cout<<ans;
    return 0;
}