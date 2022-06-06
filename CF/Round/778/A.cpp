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
        vector<int> arr;
        for(int i=0;i<n;i++) {
            int in;
            cin>>in;
            arr.push_back(in);
        }
        sort(arr.begin(),arr.end(),greater<int>());
        cout<<arr[0]+arr[1]<<endl;
    }
    return 0;
}