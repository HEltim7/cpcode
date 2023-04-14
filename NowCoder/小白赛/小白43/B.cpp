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
        LL a,b,aim;
        cin>>a>>b>>aim;
        if(a==aim||b==aim) cout<<0<<endl;
        else if(aim&1) cout<<-1<<endl;
        else if(a>aim||b>aim) cout<<1<<endl;
        else{
            int ans=1;
            a=a+b;
            while(a*2<aim) a*=2,ans++;
            cout<<ans<<endl;
        }
    }
    return 0;
}