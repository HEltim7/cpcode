#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;
int arr[N];

struct Node {
    int l,r;
    int cnt;
} tr[N];
int idx;

int new_node() {
    assert(idx<N);
    return ++idx;
}

void pushup(int u) {

}

void merge(int u,int v) {

}

void split(int u) {

}

void sort() {

}

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    
    while(m--) {
        int op,l,r;
        cin>>op>>l>>r;
        
    }
    int q;
    cin>>q;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}