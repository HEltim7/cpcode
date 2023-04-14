#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,minn=1e9,maxx=0,mincnt=0,maxcnt=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in==maxx) maxcnt++;
        else if(in>maxx) maxcnt=1,maxx=in;
        if(in==minn) mincnt++;
        else if(in<minn) mincnt=1,minn=in;
    }
    if(maxx!=minn) cout<<2LL*maxcnt*mincnt<<endl;
    else cout<<2LL*maxcnt*(maxcnt-1)/2<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}