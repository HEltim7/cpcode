#include<iostream>
using namespace std;

const int N=2e5+10;
char c[N];
int prefix[10][N];
char cmp[10][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++){
        cmp[1][i]='a'+i%3;
        cmp[2][i]='a'+(i+1)%3;
        cmp[3][i]='a'+(i+2)%3;

        cmp[4][i]='a'+2*i%3;
        cmp[5][i]='a'+2*(i+1)%3;
        cmp[6][i]='a'+2*(i+2)%3;
    }

    for(int i=1;i<=6;i++){
        for(int j=1;j<=n;j++){
            prefix[i][j]=prefix[i][j-1];
            if(cmp[i][j]!=c[j]) prefix[i][j]++;
        }
    }

    while(m--){
        int l,r;
        cin>>l>>r;
        int ans=0x3f3f3f3f;
        for(int i=1;i<=6;i++) ans=min(ans,prefix[i][r]-prefix[i][l-1]);
        cout<<ans<<endl;
    }
    return 0;
}