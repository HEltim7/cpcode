#include<iostream>
using namespace std;
const int N=1e3+10;
int pack[N][N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,v,vi,wi;
    cin>>n>>v;
    for(int i=1;i<=n;i++){
        cin>>vi>>wi;
        for(int j=1;j<=v;j++){
            pack[i][j]=pack[i-1][j];
            if(j>=vi) pack[i][j]=max(pack[i-1][j],pack[i-1][j-vi]+wi);
        }
    }
    cout<<pack[n][v];
    return 0;
}