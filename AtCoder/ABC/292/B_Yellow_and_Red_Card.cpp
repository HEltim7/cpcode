#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=110;
int cnt[N];

void solve() {
    int n,q;
    cin>>n>>q;
    while(q--) {
        int op,x;
        cin>>op>>x;
        if(op==1) cnt[x]++;
        else if(op==2) cnt[x]+=2;
        else cout<<(cnt[x]>=2?"Yes":"No")<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}