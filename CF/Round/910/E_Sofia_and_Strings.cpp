#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;

    using Heap=priority_queue<int,vector<int>,greater<int>>;
    vector<Heap> heap(1<<7);
    for(int i=0;i<n;i++) heap[s[i]].emplace(i);

    for(int i=0;i<m;i++) {
        if(heap[t[i]].empty()) {
            cout<<"NO"<<endl;
            return;
        }
        int p=heap[t[i]].top();
        heap[t[i]].pop();
        for(int j='a';j<t[i];j++) {
            while(heap[j].size()&&heap[j].top()<p) heap[j].pop();
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}