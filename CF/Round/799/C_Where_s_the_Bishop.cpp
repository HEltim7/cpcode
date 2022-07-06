#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
char board[10][10];

void solve() {
    int n=8;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) 
            cin>>board[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) {
            int mvr[]={1,1,-1,-1,0};
            int mvc[]={1,-1,1,-1,0};
            for(int k=0;k<5;k++) {
                int r=i+mvr[k];
                int c=j+mvc[k];
                if(board[r][c]!='#') break;
                if(k+1==5) {
                    cout<<i<<' '<<j<<endl;
                    return;
                }
            }
        }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}