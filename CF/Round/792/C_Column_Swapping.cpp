#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=2e5+10;

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid;
    set<PII> st;
    for(int i=0;i<n;i++) {
        vector<int> cur;
        for(int j=0;j<m;j++) {
            int in;
            cin>>in;
            cur.push_back(in);
        }
        vector<int> bak(cur);
        sort(bak.begin(),bak.end());
        PII tmp={-1,-1};
        for(int i=0;i<cur.size();i++)
            if(cur[i]!=bak[i]) {
                if(tmp.first==-1) tmp.first=i;
                else tmp.second=i;
            }
        debug(i,tmp);
        if(tmp.first!=-1) st.insert(tmp);
        grid.push_back(cur);
    }
    debug(st);
    if(st.size()>=2) cout<<"-1"<<endl;
    else{
        auto [a,b]=*st.begin();
        for(int i=0;i<n;i++){
            swap(grid[i][a],grid[i][b]);
            if(!is_sorted(grid[i].begin(),grid[i].end())) {
                cout<<"-1"<<endl;
                return;
            }
        }
        cout<<a+1<<' '<<b+1<<endl;
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