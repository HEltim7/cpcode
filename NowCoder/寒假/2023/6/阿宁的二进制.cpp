#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,q;
    cin>>n>>q;
    priority_queue<int> heap;
    vector<int> ans;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        heap.push(in);
    }
    
    ans.push_back(heap.top());
    while(heap.top()>1) {
        int cur=heap.top();
        heap.pop();
        heap.push(__builtin_popcount(cur));
        ans.push_back(heap.top());
    }

    while(q--) {
        int k;
        cin>>k;
        cout<<ans[min(k,int(ans.size())-1)]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}