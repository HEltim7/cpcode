#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    string A,B;
    cin>>A>>B;
    if(A<B) {
        if(A.front()!=B.front()) cout<<2<<' '<<2<<endl;
        else cout<<1<<' '<<1<<endl;
    }
    else {
        for(int i=0;i<n;i++) 
            if(A[i]!=B[i]) {
                cout<<i+1<<' '<<i+1<<endl;
                return;
            }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}