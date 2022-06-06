#include<iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL n,m,x,maxx=0;
    int k;
    cin>>n>>m>>k;
    if(n>m) n=m+1;
    maxx=(2*m+1+n)*n/2;

    while(k--){
        LL x;
        cin>>x;
        if(x>maxx||m==1&&x==3||m==2&&x==8) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}