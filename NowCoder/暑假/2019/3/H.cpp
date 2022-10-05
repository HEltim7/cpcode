#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;

void solve() {
    vector<PII> poi;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        poi.emplace_back(x,y);
    }
    sort(poi.begin(),poi.end());
    auto [x,y]=poi[n/2-1];
    if(poi[n/2].first==x) {
        int mv=9.99e8;
        cout<<x-1<<' '<<y+1+mv<<' ';
        cout<<x+1<<' '<<y-mv<<endl;
    }
    else {
        int mv=1e9;
        cout<<x<<' '<<mv<<' ';
        cout<<x+1<<' '<<-mv<<endl;
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