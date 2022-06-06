#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int a,ans=0;
    cin>>a;
    for(int i=2;i<=a-1;i++){
        int tmp=a;
        while(tmp){
            ans+=tmp%i;
            tmp/=i;
        }
    }
    int x=gcd(ans,a-2);
    cout<<ans/x<<'/'<<(a-2)/x;
}