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
        LL a,b;
        cin>>a>>b;
        if(a==0) cout<<1<<endl;
        else cout<<a+b*2+1<<endl;
    }
    return 0;
}