#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m),c;
    for(int &x:a) cin>>x,c.push_back(x);
    for(int &x:b) cin>>x,c.push_back(x);
    sort(c.begin(),c.end());
    for(int x:a) {
        cout<<lower_bound(c.begin(),c.end(),x)-c.begin()+1<<' ';
    }
    cout<<endl;
    for(int x:b) {
        cout<<lower_bound(c.begin(),c.end(),x)-c.begin()+1<<' ';
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}