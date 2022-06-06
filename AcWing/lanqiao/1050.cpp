#include<iostream>
#include<cstring>
using namespace std;
const int N=1e2+10;
int matrix[N][N];
int maxx[N][N];
int t,r,c;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>t;
    while(t--){
        memset(maxx,0,sizeof maxx);
        cin>>r>>c;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cin>>matrix[i][j];
            }
        }
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                maxx[i][j]=max(maxx[i-1][j],maxx[i][j-1])+matrix[i][j];
            }
        }
        cout<<maxx[r][c]<<'\n';
    }
    return 0;
}