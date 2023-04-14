#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int arr[N];

void solve() {
    int n;
    LL c,d,ans=0,base=0;
    cin>>n>>c>>d;
    // map<int,int> mp;
    set<int> st;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) {
        if(st.count(arr[i])) base+=c;
        else st.insert(arr[i]);
    }

    // auto cal=[&](int mid) {
    //     LL res=base+mid*d;
    //     for(int x:st) {
    //         if(x>mid) res+=c;
    //         else res-=d;
    //     }
    //     return res;
    // };

    ans=n*c+d;
    int suf=n,last=0;
    LL res=n*c;
    for(int x:st) {
        int len=x-last-1;
        res+=len*d;
        res-=c;
        last=x;
        ans=min(ans,res);
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