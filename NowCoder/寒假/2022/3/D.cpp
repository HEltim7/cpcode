#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin>>s>>s;
    int idx1,idx0;
    for(int i=0;i<s.size();i++) if(s[i]=='1') idx1=i;
    for(int i=0;i<s.size();i++) if(s[i]=='0') idx0=i;
    swap(s[idx1],s[idx0]);
    cout<<s;
    return 0;
}