#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e2+10;
int tab[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            string in;
            cin>>in;
            for(int j=0;j<m;j++){
                tab[i][j+1]=in[j]-'0';
                if(tab[i][j+1]) ans++;
            }
        }
        if(tab[1][1]) cout<<-1<<endl;
        else{
            cout<<ans<<endl;
            for(int i=n;i>=1;i--)
                for(int j=m;j>=1;j--){
                    if(tab[i][j]&&j!=1){
                        cout<<i<<' '<<j-1<<' '<<i<<' '<<j<<endl;
                    }
                    else if(tab[i][j]){
                        cout<<i-1<<' '<<j<<' '<<i<<' '<<j<<endl;
                    }
                } 
        }
    }
    return 0;
}