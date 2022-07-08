#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
int arr[3][3];

void solve() {
    int in,cnt=0;
    for(int i=1;i<=4;i++) {
        cin>>in;
        if(in) cnt++;
    }
    if(cnt==4) cout<<2<<endl;
    else if(cnt==0) cout<<0<<endl;
    else cout<<1<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}