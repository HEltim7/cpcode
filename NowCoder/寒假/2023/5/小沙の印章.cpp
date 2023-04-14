#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    cout<<n<<endl;
    vector<int> id(n+1);
    for(int i=1;i<=n;i++) id[i]=i;
    for(int i=1;i<=n;i++) {
        if(i&1) {
            cout<<(n-1)/2<<endl;
            for(int j=2;j+1<=n;j+=2) {
                cout<<id[j]<<' '<<id[j+1]<<endl;
                swap(id[j],id[j+1]);
            }
        }
        else {
            cout<<n/2-1<<endl;
            for(int j=3;j+1<=n;j+=2) {
                cout<<id[j]<<' '<<id[j+1]<<endl;
                swap(id[j],id[j+1]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}