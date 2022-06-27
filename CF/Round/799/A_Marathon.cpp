#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int arr[5],res=0;
    for(int i=1;i<=4;i++) {
        cin>>arr[i];
        if(i>1&&arr[i]>arr[1])
            res++;
    }
    cout<<res<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}