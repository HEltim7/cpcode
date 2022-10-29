#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e5+10;
int cnt[N];

void solve() {
    int n,x;
    cin>>n>>x;
    for(int i=1,in;i<=n;i++) cin>>in,cnt[in]++;
    for(int i=1;i<x;i++) {
        if(cnt[i]) {
            int ne=cnt[i]/(i+1);
            cnt[i]-=ne*(i+1);
            cnt[i+1]+=ne;
            if(cnt[i]) {
                cout<<"No"<<endl;
                return;
            }
        }
    }
    cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}