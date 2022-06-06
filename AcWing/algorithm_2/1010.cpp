#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=1e3+10;
int num[N];
int lis[N];
int g[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n=0;
    while(cin>>num[n+1]) n++;
    // debug(n);

    for(int i=1;i<=n;i++){
        lis[i]=1;
        for(int j=1;j<i;j++) if(num[i]<=num[j]) lis[i]=max(lis[i],lis[j]+1);
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,lis[i]);
    cout<<ans<<endl;

    int cnt=0;
    for(int i=1;i<=n;i++){
        int j=0;
        while(j<=cnt) if(g[++j]>=num[i]) break;
        g[j]=num[i];
        if(j>cnt) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}