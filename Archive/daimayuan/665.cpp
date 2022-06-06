#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=110,H=60;
LL num[N],dp[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>num[i];
    
    for(int i=H;~i;i--){
        
    }
}
/*
从高位往底位贪
每次check() 为O(n^3)

dp[j][k]=j位置，切了k刀，且当前切了的？值

*/