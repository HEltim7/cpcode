#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=30;

void solve() {
    vector<bool> mark[2];
    mark[0].resize(30);
    mark[1].resize(30);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        for(int j=0;j<=20;j++) {
            if(in&(1<<j)) mark[1][j]=1;
            else mark[0][j]=1;
        }
    }
    for(int j=0;j<=20;j++)
        if(mark[0][j]&&mark[1][j]) ans|=1<<j;
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}