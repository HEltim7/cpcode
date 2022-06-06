#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++) cin>>arr[i];
        arr[n+1]=arr[n];
        for(int i=2;i<n;i++) {
            if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
                arr[i+1]=max(arr[i],arr[i+2]);
                ans++;
            }
        }
        cout<<ans<<endl;
        for(int i=1;i<=n;i++) cout<<arr[i]<<" \n"[i==n];
    }
    return 0;
}