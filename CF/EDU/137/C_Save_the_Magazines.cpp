#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int val[N];

void solve() {
    int n;
    string s;
    cin>>n>>s;
    s="0"+s+"0";
    for(int i=1;i<=n;i++) cin>>val[i];

    int ans=0;
    for(int i=1;i<=n;) {
        if(s[i]=='1'&&s[i-1]=='0') {
            int minn=2e9+10;
            int sum=0;
            int j=i;
            for(;j<=n&&s[j]=='1';j++) {
                minn=min(minn,val[j]);
                sum+=val[j];
            }
            ans+=sum+max(val[i-1]-minn,0);
            i=j+1;
        }
        else i++;
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