#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int a[N],b[N];

void solve() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++) 
        if(a[i]>b[i]) {
            cout<<"NO"<<endl;
            return;
        }
    for(int i=0;i<n;i++)
        if(b[i]-b[(i+1)%n]>=2&&a[i]!=b[i]) {
            cout<<"NO"<<endl;
            return;
        }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}