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
#define cat(...)
#define cat_arr(...)
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
        int l=-1,r=-1;
        for(int i=1;i<n;i++)
            if(arr[i+1]==arr[i]){
                if(l==-1) l=i;
                else r=i+1;
            }
        cat(l,r);
        if(r==-1) cout<<0<<endl;
        else if(r-l+1==3) cout<<1<<endl;
        else cout<<r-l-2<<endl;
    }
    return 0;
}