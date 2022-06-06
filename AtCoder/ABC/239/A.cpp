#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    double x;
    cin>>x;
    cout<<fixed<<setprecision(9)<<sqrt(x*(12800000+x));
    return 0;
}