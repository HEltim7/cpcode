#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=1e5+10;
int num[N];
int dif[N];
int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while (t--){
        ans=1;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) dif[i]=0;
        for(int i=1;i<=n;i++){
            cin>>num[i];
            dif[i]+=num[i],dif[i+1]-=num[i];
        }

        for(int l=1,r=2;r<=n;r++){
            if(__gcd(abs(dif[r-1]),abs(dif[r]))==1){
                l=r-1;
            }
            else{
                ans=max(ans,r-l+1);
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}