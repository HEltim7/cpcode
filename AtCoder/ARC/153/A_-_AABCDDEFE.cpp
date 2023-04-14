#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e9;
int num[20];

void solve() {
    int n;
    cin>>n;
    n+=int(1e5)-1;
    vector<int> ans;
    while(n) {
        int t=n%10;
        n/=10;
        ans.push_back(t);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i];
        if(i==0||i==3) cout<<ans[i];
    }
    cout<<*++ans.rbegin();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}