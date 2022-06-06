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
        LL x,y;
        cin>>x>>y;
        if(y%x) {
            cout<<"0 0"<<endl;
            continue;
        }
        if(x==y) {
            cout<<"1 1"<<endl;
            continue;
        }
        LL t=y/x;
        cout<<1<<' '<<t<<endl;
    }
    return 0;
}