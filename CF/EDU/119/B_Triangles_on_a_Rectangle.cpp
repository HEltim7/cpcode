#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    LL w,h,ans=0;
    cin>>w>>h;
    int k;
    for(int i=1;i<=4;i++) {
        cin>>k;
        LL minn=-1,maxx=-1;
        for(int j=1;j<=k;j++) {
            int in;
            cin>>in;
            if(j==1) minn=in;
            if(j==k) maxx=in;
        }
        if(i<=2) ans=max(ans,(maxx-minn)*h);
        else ans=max(ans,(maxx-minn)*w);
    }
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