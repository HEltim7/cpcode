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
        vector<pair<int,int>> res;
        for(int i=1;i<=n;i++){
            int in;
            cin>>in;
            res.push_back({in,i});
        }
        sort(res.begin(),res.end());
        int a=res.front().second;
        int b=res.back().second;
        if(a>b) swap(a,b);
        cout<<a<<' '<<b<<endl;
    }
    return 0;
}