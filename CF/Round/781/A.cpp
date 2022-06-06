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
        if(n&1){
            n-=2;
            cout<<n/2<<' '<<n/2+1<<' '<<1<<' '<<1<<endl;
        }
        else if(n%4==0)
            for(int i=1;i<=4;i++)
                cout<<n/4<<" \n"[i==4];
        else{
            n-=2;
            cout<<n/2-1<<' '<<n/2+1<<' '<<1<<' '<<1<<endl;
        }
    }
    return 0;
}