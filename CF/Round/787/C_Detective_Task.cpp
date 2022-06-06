#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        s=" "+s;

        int one=1,zero=s.size()-1;
        for(int i=1;i<s.size();i++) 
            if(s[i]=='1') one=i;
        for(int i=s.size()-1;i>=1;i--)
            if(s[i]=='0') zero=i;
        cout<<zero-one+1<<endl;
    }
    return 0;
}