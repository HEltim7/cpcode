#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
const int N=1e4+10;
int T[N],D[N];
int n,tidx,didx;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        string op;
        int in;
        cin>>op>>in;
        if(op[0]=='T') T[++tidx]=in;
        else D[++didx]=in;
    }
    D[++didx]=1000;
    sort(T+1,T+1+tidx);
    sort(D+1,D+1+didx);
    double loc=0,ans=0;
    int speed=1,i=1,j=1;
    for(;;){
        if(i==tidx+1&&j==didx+1) break;
        double nextime=(D[j]-loc)*speed+ans;
        if(i==tidx+1||nextime<T[i]) ans+=(D[j]-loc)*speed,loc=D[j++];
        else loc+=(T[i]-ans)/speed,ans=T[i++];
        speed++;
    }
    cout<<(int)(ans+0.5);
    return 0;
}