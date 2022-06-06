#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    LL ans=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        LL in;
        cin>>in;
        ans=max(in,ans);
    }
    cout<<ans*2;
    return 0;
}