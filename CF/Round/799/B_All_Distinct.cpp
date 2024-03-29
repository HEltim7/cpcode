#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e4+10;
int cnt[N];

void solve() {
    int n;
    cin>>n;
    int res=0,cnts=0;
    vector<int> arr;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        arr.push_back(in);
        cnt[in]++;
        if(cnt[in]==1) res++;
        else cnts++;
    }
    for(auto x:arr) cnt[x]=0;
    cout<<res-(cnts&1)<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}