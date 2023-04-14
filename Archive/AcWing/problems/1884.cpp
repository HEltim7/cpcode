#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string cow;
    int n,c=0;
    LL ans=0,res=0;
    cin>>n>>cow;
    for(auto x:cow){
        if(x=='C') c++;
        else if(x=='O') res+=c;
        else ans+=res;
    }
    cout<<ans;
    return 0;
}