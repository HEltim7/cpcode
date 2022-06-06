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
        int n,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int in;
            cin>>in;
            sum+=in-1;
        }
        if(sum&1) cout<<"errorgorn"<<endl;
        else cout<<"maomao90"<<endl;
    }
    return 0;
}