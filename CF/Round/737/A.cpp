#include <iostream>
#include <iomanip>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        double sum=0,maxx=-1e9,in;
        for(int i=1;i<=n;i++){
            cin>>in;
            sum+=in;
            maxx=max(maxx,in);
        }
        sum-=maxx;
        cout<<fixed<<setprecision(9)<<maxx+sum/(n-1)<<endl;
    }
    return 0;
}