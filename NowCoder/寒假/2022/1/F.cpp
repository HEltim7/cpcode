#include<iostream>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            int in;
            cin>>in;
            if(in>=m) ans++;
            else ans--;
        }
        if(ans>0) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}