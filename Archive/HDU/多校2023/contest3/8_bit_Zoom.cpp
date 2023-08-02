#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e3+10;
char grid[N][N],tmp[N][N],ans[N][N];

void solve() {
    int n,z;
    cin>>n>>z;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>grid[i][j];
    
    if(n*z%100) {
        cout<<"error"<<endl;
        return;
    }

    int r=z*4/100;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            for(int x=i*r;x<(i+1)*r;x++) {
                for(int y=j*r;y<(j+1)*r;y++) {
                    tmp[x][y]=grid[i][j];
                }
            }
        }
    }

    int m=n*r/4;
    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
            char t=tmp[i*4][j*4];
            for(int x=i*4;x<(i+1)*4;x++) {
                for(int y=j*4;y<(j+1)*4;y++) {
                    if(tmp[x][y]!=t) {
                        cout<<"error"<<endl;
                        return;
                    }
                }
            }
            ans[i][j]=t;
        }
    }

    for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++)
            cout<<ans[i][j];
        cout<<endl;
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