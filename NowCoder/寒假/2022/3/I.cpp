#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int N=1e5+10;
int c[5][N];

LL ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,l,r;
    cin>>n>>l>>r;
    string passwd;
    getline(cin,passwd);
    getline(cin,passwd);
    passwd=" "+passwd;

    for(int i=n;i>=1;i--){
        char x=passwd[i];
        for(int j=1;j<=4;j++) c[j][i]=c[j][i+1];
        if(x>='A'&&x<='Z') c[1][i]=i;
        else if(x>='a'&&x<='z') c[2][i]=i;
        else if(x>='0'&&x<='9') c[3][i]=i;
        else c[4][i]=i;
    }
    int t[10];
    for(int i=1;i<=n-l+1;i++){
        int cnt=0;
        for(int j=1;j<=4;j++){
            if(c[j][i]) cnt++;
            t[j]=c[j][i];
        }
        if(cnt<3) continue;

        int maxx=i+l-1;
        sort(t+1,t+1+4);
        if(cnt==4) maxx=max(maxx,t[3]);
        else maxx=max(maxx,t[4]);
        if(maxx>i+r-1) continue;

        ans+=max(0,min(n,i+r-1)-maxx+1);
    }
    cout<<ans;
    return 0;
}