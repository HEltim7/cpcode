#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n,x,d,c;
    cin>>c;
    while(c--){
        cin>>n>>x>>d;
        ll t=d/x;
        ll ans=0;
        if(n-t>0) ans=(n-t)*t+t*(t-1)/2;
        else{
            t=n;
            ans=t*(t-1)/2;
        }
        // debug(t);
        cout<<ans<<endl;
    }
    return 0;
}