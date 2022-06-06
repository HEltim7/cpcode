#include<iostream>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        if(in>ans) ans=in;
        else break;
    }
    cout<<ans;
    return 0;
}