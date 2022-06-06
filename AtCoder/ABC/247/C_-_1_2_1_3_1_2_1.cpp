#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void print(int n){
    if(n==0) return;
    print(n-1);
    cout<<n<<' ';
    print(n-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    print(n);
    return 0;
}