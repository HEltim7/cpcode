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
        int n,k;
        cin>>n>>k;
        string  in;
        cin>>in;
        string tmp=in;
        reverse(tmp.begin(),tmp.end());
        if(k==0||tmp==in) cout<<1<<endl;
        else cout<<2<<endl;
    }
    return 0;
}