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
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr.begin(),arr.end());
        if(n==1){
            if(arr.back()>1) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            continue;
        }
        if(arr[n-1]-arr[n-2]>1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}