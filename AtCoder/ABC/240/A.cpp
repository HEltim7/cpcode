#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    if(a+1==b||(a==1&&b==10)) cout<<"Yes";
    else cout<<"No";
    return 0;
}