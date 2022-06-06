#include<iostream>
using namespace std;

// #define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n&1){
            int mid=n>>1;
            if(mid&1) cout<<mid+2<<' '<<mid-2<<' '<<1<<endl;
            else cout<<mid+1<<' '<<mid-1<<' '<<1<<endl;
        }
        else cout<<n-3<<' '<<2<<' '<<1<<endl;
    }
    return 0;
}