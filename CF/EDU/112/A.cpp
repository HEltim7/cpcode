#include <iostream>
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
        ll n;
        cin>>n;
        if(n<=6){
            cout<<15<<endl;
            continue;
        }
        cout<<(n+1)/2*5<<endl;
    }
    return 0;
}