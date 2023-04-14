#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6;
int pre[N+10];

void init() {
    auto check=[](int x) {
        int cnt=0;
        while(x) {
            cnt+=x%10>0;
            x/=10;
        }
        return cnt==1;
    };

    for(int i=1;i<=N;i++) {
        pre[i]=pre[i-1]+check(i);
    }
}

void solve() {
    int n;
    cin>>n;
    cout<<pre[n]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    init();
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}