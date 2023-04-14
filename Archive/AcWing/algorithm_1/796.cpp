#include<iostream>
using namespace std;

typedef long long ll;
const int N=1e3+10;
ll matrix[N][N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>matrix[i][j];
            matrix[i][j]+=matrix[i-1][j]+matrix[i][j-1]-matrix[i-1][j-1];
        }
    }
    while(q--){
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        cout<<matrix[r2][c2]+matrix[r1-1][c1-1]-matrix[r1-1][c2]-matrix[r2][c1-1]<<'\n';
    }
    return 0;
}