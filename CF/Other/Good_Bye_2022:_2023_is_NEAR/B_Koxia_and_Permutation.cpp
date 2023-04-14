#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n,k;
    cin>>n>>k;
    deque<int> q(n);
    for(int i=0;i<n;i++) q[i]=i+1;
    while(q.size()) {
        cout<<q.back()<<' ';
        q.pop_back();
        if(q.size()) {
            cout<<q.front()<<' ';
            q.pop_front();
        }
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}