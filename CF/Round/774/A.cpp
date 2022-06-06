#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        LL n,s;
        cin>>n>>s;
        cout<<s/(n*n)<<endl;
    }
    return 0;
}