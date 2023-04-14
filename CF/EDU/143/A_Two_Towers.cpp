#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,m;
    string a,b;
    cin>>n>>m>>a>>b;
    
    while(b.size()>=2) {
        a.push_back(b.back());
        b.pop_back();
    }

    int cnt=0;
    for(int i=1;i<a.size();i++) if(a[i]==a[i-1]) cnt++;

    while(cnt&&a.size()>=2) {
        auto it=a.rbegin();
        if(*it==it[1]) cnt--;
        if(*it==b.back()) {
            cnt++;
            break;
        }
        b.push_back(a.back());
        a.pop_back();
    }
    if(cnt==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}