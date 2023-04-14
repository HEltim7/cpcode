#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=4e5+10;
int arr[N];

void solve() {
    int n;
    cin>>n;

    auto work=[&]() {
        LL ans=1e15;
        LL res=0;
        for(int i=1;i<=2*n;i++) res+=abs(arr[i]-(-1));
        for(int i=1;i<=2*n;i++) 
            ans=min(ans,res-abs(arr[i]-(-1))+abs(arr[i]-n));
        return ans;
    };

    auto zero=[&]() {
        LL ans=0;
        for(int i=1;i<=2*n;i++) ans+=abs(arr[i]-0);
        return ans;
    };

    for(int i=1;i<=2*n;i++) cin>>arr[i];
    if(n==1) cout<<abs(arr[2]-arr[1])<<endl;
    else if(n==2) {
        LL ans=1e15;
        LL res=0;
        for(int i=1;i<=2*n;i++) res+=abs(arr[i]-2);
        ans=min(ans,res);
        
        ans=min(ans,work());
        ans=min(ans,zero());
        cout<<ans<<endl;
    }
    else if(n&1) cout<<zero()<<endl;
    else cout<<min(zero(),work())<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}