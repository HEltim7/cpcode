#include <iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef long long ll;
const int N=1e3+10;
ll snack[N];
ll n,k;
ll ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>snack[i];
    }
    sort(snack+1,snack+1+n);
    for(int i=k;i>=1;i--) ans+=snack[i];
    cout<<ans;
    return 0;
}