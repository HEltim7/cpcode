#include <limits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<string> res(n,string(n,'.'));
    if(n&1) {
        for(int i=0; i<n; i+=2) {
            res[0][i]='U';
            res[n-1][i]='D';
        }
        for(int i=1; i<n; i+=2) {
            res[i][0]='L';
            res[i][n-1]='R';
        }
        for(int i=1; i<=n-1; ++i)
            for(int j=1; j<=n-2; j+=2) {
                res[i][j]='U';
            }
    }else {
        for(int i=0; i<n/2; ++i) {
            // (i,i)->(n-1-i,n-1-i)
            int e=n-1-i;
            res[i][i]='L';
            res[i][e]='U';
            res[e][i]='D';
            res[e][e]='R';
            for(int j=i+1; j<e; ++j) {
                if((j-i)&1) {
                    res[i][j]='U';
                    res[j][e]='R';
                }else {
                    res[e][j]='D';
                    res[j][i]='L';
                }
            }
        }
    }
    for(int i=0; i<n; ++i) cout<<res[i]<<'\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}