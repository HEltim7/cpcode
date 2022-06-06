#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int x,y;
    cin>>x>>y;
    int d2=x*x+y*y;
    double c=sqrt((double)y*y/d2);
    double r=sqrt(1-c*c);
    cout<<fixed<<setprecision(8)<<r<<' '<<c;
    return 0;
}