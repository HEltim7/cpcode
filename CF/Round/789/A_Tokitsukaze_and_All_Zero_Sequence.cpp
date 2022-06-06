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
        bool res=0;
        for(int i=1;i<=n;i++){
            int in;
            cin>>in;
            if(in==0) res=1;
            else arr.push_back(in);
        }
        sort(arr.begin(),arr.end());
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]) res=1;
        }
        if(res) cout<<arr.size()<<endl;
        else cout<<arr.size()+1<<endl;
    }
    return 0;
}