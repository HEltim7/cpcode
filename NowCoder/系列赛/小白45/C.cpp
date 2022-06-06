#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
LL a[10],ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    for(int i=1;i<=8;i++) cin>>a[i];
    for(int i=1;i<=8;i++){
        LL x=a[i]/3;
        LL y=a[i]%3;
        if(y==0){
            ans+=i*x*3;
        }
        else if(y==1){
            if(x) ans+=i*x*3+i;
        }
        else {
            if(x>=2) ans+=i*x*3+i+i;
            else if(x>=1) ans+=i*x*3+i;
        }
        a[i+1]+=x;
    }
    cout<<ans;
    return 0;
}