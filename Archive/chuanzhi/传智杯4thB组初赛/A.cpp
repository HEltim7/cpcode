#include<iostream>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    int res=a*0.2+b*0.3+c*0.5;
    cout<<res;
    return 0;
}