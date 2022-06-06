#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    LL hp,a,b,ans=0;
    cin>>hp>>a>>b>>s;
    for(auto x:s){
        if(x=='1'&&hp>=a) ans++,hp-=a;
        else hp+=b;
    }
    cout<<ans;
    return 0;
}