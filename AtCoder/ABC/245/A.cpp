#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int taka=a*3600+b*60;
    int aoki=c*3600+d*60+1;
    if(taka<aoki) cout<<"Takahashi";
    else cout<<"Aoki";
    return 0;
}