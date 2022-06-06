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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int one=0,zero=0;
        for(auto x:s) if(x=='1') one++; else zero++;
        if(n>=3||one>=2||zero>=2) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}