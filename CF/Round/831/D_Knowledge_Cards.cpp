#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
bool mark[N];

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    int tot=n*m-3;
    for(int i=1;i<=k;i++) mark[i]=0;
    vector<int> arr(k);
    for(auto &x:arr) cin>>x;
    reverse(arr.begin(),arr.end());

    for(int i=k;i>=1;i--) {
        while(!mark[i]) {
            mark[arr.back()]=1;
            arr.pop_back();
            tot--;
        }

        if(tot<0) {
            cout<<"TIDAK"<<endl;
            return;
        }

        mark[i]=0;
        tot++;
    }
    cout<<"YA"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}