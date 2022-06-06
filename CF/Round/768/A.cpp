#include<iostream>
#include<cmath>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int INF=0x3f3f3f3f;
const int N=1e4+10;
int a[N],b[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int maxx=0,minn=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++){
            if(a[i]<b[i]) swap(a[i],b[i]);
        }
        for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
        for(int i=1;i<=n;i++) minn=max(minn,b[i]);

        cout<<maxx*minn<<endl;
    }
    return 0;
}