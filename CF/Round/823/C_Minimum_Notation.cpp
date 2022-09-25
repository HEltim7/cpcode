#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
int rmax[1<<7];

void solve() {
    for(int i='0';i<='9';i++) rmax[i]=0;
    string s,t;
    cin>>s;
    for(int i=0;i<s.size();i++) rmax[s[i]]=i;
    t=s;
    sort(t.begin(),t.end());
    int len=0;
    for(int j=0;j<s.size();j++) {
        if(s[j]==t[len]) len++;
        while(len<t.size()&&rmax[t[len]]<=j) 
            t[len]=min('9',char(t[len]+1)),len++;
    }
    // for(int i=len;i<t.size();i++) t[i]=min('9',char(t[i]+1));
    cout<<t<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}