#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a,b;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        a.push_back(in);
    }
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        b.push_back(in);
    }
    int maxx=0;
    for(int i=0;i<n;i++) maxx=max(maxx,a[i]-b[i]);
    for(auto &x:a) x=max(x-maxx,0);
    cout<<(a==b?"YES":"NO")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}