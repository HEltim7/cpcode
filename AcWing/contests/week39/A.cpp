#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        ans+=abs(in);
    }
    cout<<ans;
    return 0;
}