#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e4+10;
int cnt[N];
vector<int> num[N];

void solve() {
    int m;
    cin>>m;
    for(int i=1;i<=m;i++) {
        int n;
        cin>>n;
        for(int j=1;j<=n;j++) {
            int in;
            cin>>in;
            num[i].push_back(in);
            cnt[in]++;
        }
    }
    bool valid=1;
    vector<int> ans;
    for(int i=1;i<=m;i++) {
        int res=0;
        for(int x:num[i]) {
            if(--cnt[x]==0) res=x;
        }
        if(!res) {
            valid=0;
            break;
        }
        ans.push_back(res);
    }

    for(int i=1;i<=m;i++) {
        for(int x:num[i]) cnt[x]=0;
        num[i].clear();
    }
    
    if(valid) {
        for(int x:ans) cout<<x<<' ';
        cout<<endl;
    }
    else cout<<-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}