#include<iostream>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T,n,m,ans;
    cin>>T;
    while(T--){
        cin>>n>>m;
        ans=0;
        for(int i=1;i<=n;i++) ans+=i*i*m;
        cout<<ans<<endl;
    }
    return 0;
}