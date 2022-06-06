#include<iostream>
using namespace std;

#define endl '\n'
const int N=110;
char matrix[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n,m,r,c;
    cin>>t;
    while(t--){
        cin>>n>>m>>r>>c;
        bool flag=0;
        bool ans1=0;
        bool ans2=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char in;
                cin>>in;
                if(in=='B') flag=1;
                if(in=='B'&&(i==r&&j==c)) ans2=1;
                else if(in=='B'&&(i==r||j==c)) ans1=1;
            }
        }
        if(ans2) cout<<0<<endl;
        else if(ans1) cout<<1<<endl;
        else if(flag) cout<<2<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}