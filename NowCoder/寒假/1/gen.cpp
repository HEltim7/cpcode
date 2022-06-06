#include<iostream>
#include<testlib.h>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e4+10;
int n[N];

int main() {
    freopen64("in.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    int sum=1e6,t=0;
    while(sum>=3){
        n[++t]=rnd.next(3,min(sum,100000));
        sum-=n[t];
    }

    cout<<t<<endl;
    for(int i=1;i<=t;i++){
        cout<<n[i]<<endl;
        for(int j=1;j<=n[i];j++) 
            cout<<rnd.next(1,1000000000)<<' ';
        cout<<endl;
    }    
    
}