#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e2+10;
int tab[N][N];
int n,m;

//up1 up2 dn1 dn2
int mvr[]={-1,-1,0,0};
int mvc[]={-1,0,-1,0};
inline bool check(int row,int col){
    int cnt=0;
    for(int i=0;i<4;i++){
        int r=row+mvr[i];
        int c=col+mvc[i];
        if(r>=1&&r<=n&&c>=1&&c<=m&&tab[r][c]) cnt++;
    }
    return cnt==3;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            string in;
            cin>>in;
            for(int j=0;j<m;j++)
                tab[i][j+1]=in[j]-'0';
        }
        bool ans=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(check(i,j)) ans=0;
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}