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
        string in;
        cin>>in;
        int one=0,zero=0;
        for(auto x:in) if(x=='1') one++; else zero++;
        if(one==zero) cout<<one-1<<endl;
        else cout<<min(one,zero)<<endl;
    }
    return 0;
}