#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,k;
    cin>>n>>k;
    string ans;
    vector<pair<string,int>> vs;
    for(int i=1;i<=n;i++) {
        string s;
        cin>>s;
        if(s=="echo") {
            char c;
            cin>>c;
            vs.emplace_back(s,c);
        }
        else {
            int m;
            cin>>m;
            vs.emplace_back(s,m);
        }
    }

    for(int i=0;i<min(int(vs.size()),k);i++) {
        if(vs[i].first=="echo") ans.push_back(vs[i].second);
        else {
            for(int j=0;j<vs[i].second&&vs.size()<k;j++)
                vs.emplace_back(vs[j]);
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}