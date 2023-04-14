#include<iostream>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string a,b;
    cin>>a>>b;
    for(auto &x:a) if(x<='z'&&x>='a') x=x+'A'-'a';
    for(auto &x:b) if(x<='z'&&x>='a') x=x+'A'-'a';
    if(a==b) cout<<0;
    else if(a>b) cout<<1;
    else cout<<-1;
    return 0;
}