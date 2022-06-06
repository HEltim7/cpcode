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
        int n;
        cin>>n;
        int cnt=n/3;
        int rem=n%3;
        if(rem==0){
            string x="21";
            for(int i=1;i<=cnt;i++) cout<<x;
            cout<<endl;
        }
        else if(rem==1){
            cout<<1;
            string x="21";
            for(int i=1;i<=cnt;i++) cout<<x;
            cout<<endl;
        }
        else{
            string x="21";
            for(int i=1;i<=cnt;i++) cout<<x;
            cout<<2;
            cout<<endl;
        }
    }
    return 0;
}