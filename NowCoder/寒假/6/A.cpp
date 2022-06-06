#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string in;
        int k;
        cin>>in>>k;
        int ans=0;
        for(auto x:in) if(x=='+') ans++; else ans--;
        ans=abs(ans);
        int req=min(ans/2,k);
        k-=req;
        ans-=req*2;
        if(k%2&&ans%2==0) ans+=2;
        cout<<ans<<endl;
    }
    return 0;
}