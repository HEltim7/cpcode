#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    LL sum=0;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        while(in>0&&in%2==0) in/=2;
        sum+=in;
    }
    cout<<sum<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}