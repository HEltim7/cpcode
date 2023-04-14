#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
int mvr[]={1,-1,0,0};
int mvc[]={0,0,1,-1};

void solve() {
    int n,m;
    cin>>n>>m;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    auto cal=[&](int x,int y) {
        int res=0;
        for(int i=0;i<4;i++) {
            int r=x+mvr[i];
            int c=y+mvc[i];
            if(r>=1&&r<=n&&c>=1&&c<=m) res++;
        }
        return res;
    };

    cout<<min(cal(x1,y1),cal(x2,y2))<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}