#include<iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
const int N=1e3+10;
int num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    int minn,maxx;
    minn=maxx=num[1];
    for(int i=2;i<=n;i++){
        if(num[i]<minn) minn=num[i];
        if(num[i]>maxx) maxx=num[i];
    }
    for(int i=1;i<=n;i++){
        double res=(num[i]-minn)*1./(maxx-minn);
        cout<<(int)(100*res)<<' ';
    }
    return 0;
}