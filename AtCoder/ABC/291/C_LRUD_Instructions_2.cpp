#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    set<pair<int,int>> st;
    int x=0,y=0;
    st.emplace(0,0);
    for(auto c:s) {
        if(c=='U') y++;
        else if(c=='D') y--;
        else if(c=='L') x--;
        else x++;
        if(st.count({x,y})) {
            cout<<"Yes"<<endl;
            return;
        }
        st.emplace(x,y);
    }
    cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}