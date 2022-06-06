#include<vector>
#include<iostream>
#include<algorithm>
#include<tuple>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
LL arr[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>arr[i];
        if(arr[n-1]>arr[n]){
            cout<<"-1"<<endl;
            continue;
        }
        vector<tuple<int,int,int>> ans;
        bool res=1;
        for(int i=n-2;i>=1;i--){
            if(arr[i]>arr[i+1]){
                arr[i]=arr[i+1]-arr[n];
                ans.emplace_back(i,i+1,n);
                if(arr[i]>arr[i+1]){
                    res=0;
                    break;
                }
            }
        }
        if(res) {
            cout<<ans.size()<<endl;
            for(auto [a,b,c]:ans) cout<<a<<' '<<b<<' '<<c<<endl;
        }
        else cout<<"-1"<<endl;
    }
    return 0;
}