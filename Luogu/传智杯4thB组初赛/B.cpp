#include<iostream>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,p;
        cin>>a>>p;
        if(p<16) cout<<max(0,a-10)<<endl;
        else if(p>20) cout<<max(0,a-p+20)<<endl;
        else cout<<a<<endl;
    }
    return 0;
}