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
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>> arr;
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            arr.emplace_back(a,0);
        }
        for(int i=0;i<n;i++){
            int b;
            cin>>b;
            arr[i].second=b;
        }
        sort(arr.begin(),arr.end());
        for(auto [a,b]:arr){
            if(a>k) break;
            k+=b;
        }
        cout<<k<<endl;
    }
    return 0;
}