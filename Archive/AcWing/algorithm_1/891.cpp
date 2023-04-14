#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int n;
int in,ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n;
    while(n--) cin>>in,ans^=in;
    if(ans) cout<<"Yes";
    else cout<<"No";
    return 0;
}