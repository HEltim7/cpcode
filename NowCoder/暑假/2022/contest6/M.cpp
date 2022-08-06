#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=510;
char grid[N][N];
int fit[N][N];
int n,m;

bool check(int r,int c) {
    return r>=1&&r<=n&&c>=1&&c<=m;
}

int draw(int r,int c,bool stat) {
    if(fit[r][c]) return fit[r][c];
    if(!check(r, c)) return stat?1:-1;
    if(grid[r][c]!='.') return fit[r][c]=-1;
    if(r==n&&c==m) return fit[r][c]=1;
    if(stat) {
        if(draw(r+1, c, !stat)==1||draw(r, c+1, !stat)==1) fit[r][c]=1;
        else fit[r][c]=-1;
    }
    else {
        if(draw(r+1,c,!stat)==1&&draw(r,c+1,!stat)==1) fit[r][c]=1;
        else fit[r][c]=-1;
    }
    return fit[r][c];
}

int alice(int r,int c,bool stat) {
    if(fit[r][c]) return fit[r][c];
    if(!check(r, c)) return stat?1:-1;
    if(grid[r][c]=='A') return fit[r][c]=1;
    if(grid[r][c]=='B') return fit[r][c]=-1;
    if(stat) {
        if((check(r+1, c)||check(r, c+1))&&(alice(r+1, c,!stat)==1||alice(r, c+1,!stat)==1)) fit[r][c]=1;
        else fit[r][c]=-1;
    }
    else {
        if((check(r+1, c)||check(r, c+1))&&alice(r+1, c,!stat)==1&&alice(r, c+1,!stat)==1) fit[r][c]=1;
        else fit[r][c]=-1;
    }
    return fit[r][c];
}

void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>grid[i][j];

    for(int i=0;i<=n+1;i++) memset(fit[i], 0, sizeof(int)*(m+2));
    cout<<(alice(1, 1, 1)==1?"yes ":"no ");

    for(int i=0;i<=n+1;i++) memset(fit[i], 0, sizeof(int)*(m+2));
    cout<<(draw(1, 1, 1)==1?"yes ":"no ");

    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) {
            if(grid[i][j]=='A') grid[i][j]='B';
            else if(grid[i][j]=='B') grid[i][j]='A';
        }
    for(int i=0;i<=n+1;i++) memset(fit[i], 0, sizeof(int)*(m+2));
    cout<<(alice(1, 1, 1)==1?"yes\n":"no\n");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}