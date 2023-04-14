#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e5+10,INF=1e5+10;
LL num[N],ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,t;
    cin>>n>>t;
    string comet;
    cin>>comet;
    for(int i=0;i<n;i++){
        int in;
        cin>>in;
        if(comet[i]=='B') num[in]++,num[in+t]--;
        else num[in]-=INF,num[in+t]+=INF;
    }
    LL pre=0;
    for(int i=1;i<=2e5+5;i++){
        pre+=num[i];
        if(pre>0) ans++;
    }
    cout<<ans;
    return 0;
}