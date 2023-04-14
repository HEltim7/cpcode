#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int one[]={0,4,6,9,10,13};
    int two[]={8,11};
    int n,ans=0;
    cin>>n;
    if(n==0){
        cout<<1;
        return 0;
    }
    while(n){
        int t=n%16;
        n/=16;
        for(int i=0;i<6;i++) if(one[i]==t) ans++;
        for(int i=0;i<2;i++) if(two[i]==t) ans+=2;
    }
    cout<<ans;
    return 0;
}