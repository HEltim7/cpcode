#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;

void solve() {
    int n,m,take=0;
    cin>>n>>m;
    vector<int> arr;
    LL sum=0;
    int minn=1e9;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in==0) take++;
        else {
            arr.push_back(in);
            minn=min(minn,in);
        }
    }
    if(m==n) {
        cout<<"Richman"<<endl;
        return;
    }
    if(take>m) {
        cout<<"Impossible"<<endl;
        return;
    }

    int t=m-take;
    int minsuf=1e9;
    for(int i=0;i<t;i++) sum+=arr[i];
    for(int i=t;i<arr.size();i++) minsuf=min(minsuf,arr[i]);
    cout<<sum+minsuf-1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}