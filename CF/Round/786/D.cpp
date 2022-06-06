#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>arr[i];
        bool ans=1;
        int pre=0,idx=1;
        if(n&1) pre=arr[1],idx=2;
        for(int i=idx;i<=n;i+=2){
            if(min(arr[i],arr[i+1])<pre) {
                ans=0;
                break;
            }
            pre=max(arr[i],arr[i+1]);
        }

        cout<<(ans?"YES":"NO")<<endl;
    }
    return 0;
}