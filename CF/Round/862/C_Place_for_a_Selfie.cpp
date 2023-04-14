#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using LD=long double;
constexpr int N=1e5+10;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<LL> k(n);
    for(auto &x:k) cin>>x;
    sort(k.begin(),k.end());
    while(m--) {
        LL a,b,c;
        cin>>a>>b>>c;
        if(c<=0)  {
            cout<<"NO"<<endl;
            continue;
        }

        LD t=sqrt(4*a*c);
        LD l=b-t;
        LD r=b+t;
        
        auto it=upper_bound(k.begin(),k.end(),l);
        if(it!=k.end()&&*it<r) {
            cout<<"YES"<<endl;
            cout<<*it<<endl;
        }
        else cout<<"NO"<<endl;
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}