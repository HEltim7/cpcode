#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    for(auto &x:s) if(x>='A'&&x<='Z') x=x-'A'+'a';
    for(auto x:s) if(x!='a'&&x!='e'&&x!='i'&&x!='o'&&x!='u'&&x!='y')
        cout<<"."<<x;
}