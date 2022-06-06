#include<iostream>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int num,a,b,c,ans=0;
    cin>>num;
    ans+=num;
    c=num%10;
    num/=10;
    b=num%10;
    num/=10;
    a=num;
    ans+=b*100+c*10+a;
    ans+=c*100+a*10+b;
    cout<<ans;
    return 0;
}