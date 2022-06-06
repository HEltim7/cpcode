#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int ans=0;
    bool last=0;
    string s;
    cin>>s;
    for(auto x:s)
        if(x=='(') last=1;
        else if(x==')') if(last) last=0,ans+=2;
        else last=0;
    cout<<ans;
    return 0;
}