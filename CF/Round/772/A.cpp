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
        int sum=0;
        for(int i=1;i<=n;i++){
            int in;
            cin>>in;
            sum|=in;
        }
        cout<<sum<<endl;
    }
    return 0;
}