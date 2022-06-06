#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=110;
int a[N],b[N];

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) {
        int idx=i;
        for(int j=i+1;j<=n;j++) 
            if(a[j]<a[idx]) idx=j;
        if(idx!=i) {
            swap(a[i],a[idx]);
            swap(b[i],b[idx]);
            ans.emplace_back(i,idx);
        }
    }
    assert(is_sorted(a+1,a+1+n));

    for(int i=1;i<=n;i++) {
        int idx=i;
        for(int j=i+1;j<=n;j++)
            if(b[j]<b[idx]) idx=j;
        if(idx!=i) {
            if(a[i]!=a[idx]) {
                cout<<-1<<endl;
                return ;
            }
            else {
                swap(b[i],b[idx]);
                ans.emplace_back(i,idx);
            }
        }
    }

    cout<<ans.size()<<endl;
    for(auto [a,b]:ans) cout<<a<<' '<<b<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}