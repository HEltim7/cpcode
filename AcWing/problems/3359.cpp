#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int even=0,odd=0;
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        if(in&1) odd++;
        else even++;
    }
    while(even!=odd+1&&even!=odd) {
        while(even>odd+1) even--;
        while(odd>even) odd-=2,even++;
    }
    cout<<odd+even;
    return 0;
}