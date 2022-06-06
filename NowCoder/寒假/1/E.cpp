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
        if(n==m) cout<<1<<endl;
        else if(m==1) cout<<-1<<endl;
        else{
            int t=max(0,n/(m-1)-2);
            ans+=t*2;
            n-=(m-1)*t;
            while(n>0){
                if(n<=m){
                    ans++;
                    break;
                }
                n-=(m-1);
                ans+=2;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}