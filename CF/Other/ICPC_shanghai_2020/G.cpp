#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n;
    cin>>n;

    ll one=n/3*2+n%3-1;
    ll zero=n-(one+1);
    // debug(one),debug(zero);
    ll ans=zero*(zero+1)-zero*(zero+1)/2*3+zero*n;
    cout<<ans;
    return 0;
}