#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long; 
const int N=10;
char grid[N][N];

void solve(){
    int n,m;
    cin>>n>>m;
    int r=-1,c=-1;
    bool res=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='R'){
                if(r==-1&&c==-1)
                    r=i,c=j;
                else if(j<c) res=0;
            }
        } 
    if(res) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}