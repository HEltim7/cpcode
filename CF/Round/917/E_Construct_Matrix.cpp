#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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

void solve() {
    int n,k;
    cin>>n>>k;
    auto ans=vector(n,vector(n,0));

    auto put4=[&](int i,int j) {
        if(ans[i][j]||ans[i][j+1]||ans[i+1][j]||ans[i+1][j+1]) return;
        ans[i][j]=ans[i][j+1]=ans[i+1][j]=ans[i+1][j+1]=1;
        k-=4;
    };

    auto put6=[&](int i,int j) {
        ans[i][j]=ans[i][j+1]=
        ans[i+2][j+1]=ans[i+2][j+2]=
        ans[i+3][j]=ans[i+3][j+2]=1;
        k-=6;
    };

    auto put_line=[&]() {
        for(int i=0;i<n;i++) ans[n-1][i]=1;
        k-=n;
    };

    auto output=[&]() {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<ans[i][j]<<' ';
            }
            cout<<endl;
        }
    };

    if(k&1) cout<<"No"<<endl;
    else if(k==2) {
        if(n==2) {
            cout<<"Yes"<<endl;
            put_line();
            output();
        }
        else cout<<"No"<<endl;
    }
    else if(k%4==0||k<=n*n-6) {
        if(k%4) put6(0, 0);
        for(int i=0,j=0;k;) {
            put4(i, j);
            j+=2;
            if(j>=n) j=0,i+=2;
        }
        cout<<"Yes"<<endl;
        output();
    }
    else cout<<"No"<<endl;
}

/*
4 -> 0 wasted
1 1
1 1

6 -> 6 wasted
1 1 0 0
0 0 0 0
0 1 1 0
1 0 1 0

line -> n wasted
1 1 1 1
1 1 1 1
0 0 0 0
1 1 1 1
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}