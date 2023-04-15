#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=4e5+10; // !!!!!!!!!!!!!!!!!!!!
int row[N],col[N],val[N];
vector<int> id[N];

void solve() {
    map<int,LL> rowmp,colmp;
    set<pair<LL,int>> valst;
    vector<int> num;

    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int r,c,x;
        cin>>r>>c>>x;
        num.push_back(r);
        num.push_back(c);
        row[i]=r,col[i]=c,val[i]=x;
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) {
        row[i]=lower_bound(num.begin(),num.end(),row[i])-num.begin()+1;
        col[i]=lower_bound(num.begin(),num.end(),col[i])-num.begin()+1;
        id[row[i]].push_back(i);
    }
    
    LL ans=0;
    for(int i=1;i<=n;i++) {
        ans=max(ans,rowmp[row[i]]+=val[i]);
        ans=max(ans,colmp[col[i]]+=val[i]);
    }
    for(auto [x,y]:colmp) {
        valst.emplace(y,x);
    }

    for(auto [x,y]:rowmp) {
        vector<pair<LL,int>> bak;
        for(int i:id[x]) {
            int c=col[i];
            ans=max(ans,y+colmp[c]-val[i]);
            bak.emplace_back(colmp[c],c);
            valst.erase({colmp[c],c});
        }
        if(valst.size()) ans=max(ans,y+valst.rbegin()->first);
        for(auto x:bak) valst.insert(x);
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}