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
        bool one=0,two=0;
        for(int i=1;i<=n;i++){
            int in;
            cin>>in;
            arr.push_back(in);
            if(in==1) one=1;
            else if(in==0||in==2) two=1;
        }
        sort(arr.begin(),arr.end());
        bool flag=0;
        for(int i=1;i<arr.size();i++) 
            if(arr[i-1]>=3&&arr[i]-arr[i-1]==1){
                flag=1;
                break;
            }
        if(one&&two||one&&flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}