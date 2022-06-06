#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=210;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> arr;
        for(int i=1;i<=k;i++){
            int in;
            cin>>in;
            arr.push_back(in);
        }
        sort(arr.begin(),arr.end());
        int ans=max(arr.front(),n-arr.back()+1);
        for(int i=1;i<arr.size();i++) ans=max(ans,(arr[i]-arr[i-1]+2)/2);
        cout<<ans<<endl;
    }
    return 0;
}