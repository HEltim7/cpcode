#include <algorithm>
#include <array>
#include <cassert>
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
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;

    vector<int> pos;
    
    string x=s,y=t;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    if(x!=y) {
        cout<<"NO"<<endl;
        return;
    }

    for(int i=0;i<n;i++) {
        if(s[i]!=t[i]) {
            pos.push_back(i);
        }
    }
    if(pos.size()!=2) {
        if(pos.size())
            cout<<"NO"<<endl;
        else {
            sort(s.begin(),s.end());
            s.erase(unique(s.begin(),s.end()),s.end());
            if(s.size()==t.size()) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    else cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}