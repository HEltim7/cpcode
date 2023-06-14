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
    int idx1,idx2,idxn;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in==1) idx1=i;
        if(in==2) idx2=i;
        if(in==n) idxn=i;
    }

    if(idx1<idxn&&idx2<idxn) cout<<max(idx1,idx2)<<' '<<idxn<<endl;
    else if(idx1>idxn&&idx2>idxn) cout<<min(idx1,idx2)<<' '<<idxn<<endl;
    else cout<<idx1<<' '<<idx1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}