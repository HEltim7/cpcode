#include <iostream>
#include <cmath>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long double w,d;
        long double pi=3.14159265358979323846264338327950288419716939937510582097494459230781640628620899;
        cin>>w>>d;
        w=min(w,d);
        ll ans=0;
        // ans+=2*(ll)(pi/w);
        ans+=(ll)(pi/w);
        cout<<ans<<endl;
    }
    return 0;
}