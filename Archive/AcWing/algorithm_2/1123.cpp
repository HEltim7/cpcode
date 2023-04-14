#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    double a,b,c,d;
    double len=0;
    cin>>a>>b;
    while(cin>>a>>b>>c>>d){
        len+=2*sqrt((a-c)*(a-c)+(b-d)*(b-d));
    }
    int m=round(len*60/20000);
    int h=m/60;
    m%=60;
    cout<<h<<':'<<(m<10?"0":"")<<m;
    return 0;
}