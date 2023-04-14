#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int w,d,h;
    cin>>w>>d>>h;
    int a,b,f,g;
    cin>>a>>b>>f>>g;
    int ans=h+min({
        g+b+abs(f-a),
        (d-g)+(d-b)+abs(f-a),
        f+a+abs(g-b),
        (w-f)+(w-a)+abs(g-b)
    });
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