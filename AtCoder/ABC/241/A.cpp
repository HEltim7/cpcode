#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=100;
int num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n=10;
    for(int i=0;i<n;i++) cin>>num[i];
    int now=0;
    for(int i=1;i<=3;i++) now=num[now];
    cout<<now;
    return 0;
}