#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=1e3+10;
int num[N];
int sum[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++){
        sum[i]=num[i];
        for(int j=1;j<i;j++) if(num[i]>num[j]) sum[i]=max(sum[i],sum[j]+num[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,sum[i]);
    cout<<ans;
    return 0;
}