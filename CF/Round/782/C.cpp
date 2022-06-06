#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        vector<int> arr;
        arr.reserve(n+1);
        for(int i=1;i<=n;i++) cin>>arr[i];
        LL ans=0;
        int pos=0;
        for(int i=1;i<=n;i++){
            ans+=1LL*b*(arr[i]-pos);
            if(1LL*(n-i)*b>=1LL*a){
                ans+=1LL*a*(arr[i]-pos);
                pos=arr[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}