#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,in,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>in;
        if(i%2) ans^=in;
    }
    if(ans) cout<<"Yes";
    else cout<<"No";
    return 0;
}