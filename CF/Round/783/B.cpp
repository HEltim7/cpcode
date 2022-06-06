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
        int n,m;
        cin>>n>>m;
        vector<int> arr;
        for(int i=1;i<=n;i++){
            int in;
            cin>>in;
            arr.push_back(in);
        }
        sort(arr.begin(),arr.end(),greater<int>());
        int l=arr.front(),r=m-arr.front();
                
        bool ans=1;
        for(int i=1;i<arr.size();i++){
            if(l+1>=r){
                ans=0;
                break;
            }
            int d=arr[i];
            l+=d+1;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}