#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e6;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    LL n,ans=8e18;
    cin>>n;
    for(LL a=0;a<=N;a++){
        LL l=0,r=N;
        while(l<r){
            LL b=l+r>>1;
            LL t=a*a*a+a*a*b+a*b*b+b*b*b;
            if(t>=n) r=b,ans=min(ans,t);
            else l=b+1;
        }
    }
    cout<<ans;
    return 0;
}