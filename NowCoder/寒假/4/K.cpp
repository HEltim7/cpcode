#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL x,bit=0;
    cin>>x;
    LL t=x;
    while(t){
        t/=2;
        bit++;
    }
    cout<<(x<<bit)+x;
    return 0;
}