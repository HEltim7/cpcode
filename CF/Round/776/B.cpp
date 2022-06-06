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
        LL l,r,a;
        cin>>l>>r>>a;
        LL x=r/a*a-1;
        LL res=r/a+r%a;
        if(x>=l) res=max(res,x/a+x%a);
        cout<<max(res,l/a+l%a)<<endl;
    }
    return 0;
}