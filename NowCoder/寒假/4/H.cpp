#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    double x;
    cin>>x;
    cout<<fixed<<setprecision(5)<<pow(2*x/sqrt(3),3);
    return 0;
}