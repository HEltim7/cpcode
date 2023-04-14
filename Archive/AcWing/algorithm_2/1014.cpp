#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=1e3+10;
int up[N],down[N];//up从左往右求LIS,down从右往左求LIS
int num[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++){
        up[i]=1;
        for(int j=1;j<i;j++) if(num[i]>num[j]) up[i]=max(up[i],up[j]+1);
    }

    for(int i=n;i>=1;i--){
        down[i]=1;
        for(int j=n;j>i;j--) if(num[i]>num[j]) down[i]=max(down[i],down[j]+1);
    }

    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,up[i]+down[i]-1);
    cout<<ans;
    return 0;
}