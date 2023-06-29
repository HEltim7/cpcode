#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
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
    int n,k,x;
    cin>>n>>k>>x;
    if(k==1&&x==1) {
        cout<<"NO"<<endl;
        return;
    }

    if(x!=1) {
        cout<<"YES"<<endl;
        cout<<n<<endl;
        for(int i=1;i<=n;i++) cout<<1<<' ';
        cout<<endl;
    }
    else if(n==1) cout<<"NO"<<endl;
    else {
        if(k<=2&&n%2!=0) {
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
            vector<int> ans;
            if(n&1) ans.push_back(3),n-=3;
            while(n>=2) ans.push_back(2),n-=2;
            cout<<ans.size()<<endl;
            for(int x:ans) cout<<x<<' ';
            cout<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}