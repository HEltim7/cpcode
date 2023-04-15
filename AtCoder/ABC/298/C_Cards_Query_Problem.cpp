#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
multiset<int> box[N];
set<int> loc[N];


void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=q;i++) {
        int op;
        cin>>op;
        if(op==1) {
            int i,j;
            cin>>i>>j;
            box[j].insert(i);
            loc[i].insert(j);
        }
        else if(op==2) {
            int i;
            cin>>i;
            for(int x:box[i]) cout<<x<<' ';
            cout<<endl;
        }
        else {
            int i;
            cin>>i;
            for(int x:loc[i]) cout<<x<<' ';
            cout<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}