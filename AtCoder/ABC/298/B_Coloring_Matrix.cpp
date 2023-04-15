#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=110;
bool a[N][N],b[N][N],c[N][N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>b[i][j];
    
    auto rotate=[&]() {
        for(int i=1;i<=n;i++) 
            for(int j=1;j<=n;j++)
                c[i][j]=a[n-j+1][i];
        swap(a,c);
    };

    auto check=[&]() {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(a[i][j]&&!b[i][j])
                    return false;
        return true;
    };

    for(int z=1;z<=4;z++) {
        if(check()) {
            cout<<"Yes"<<endl;
            return;
        }
        rotate();
    }
    cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}