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
        string in;
        cin>>in;
        vector<int> bit;
        vector<int> cnt;
        for(auto x:in) bit.push_back(x-'0');
        bool flip=k&1;
        for(auto &x:bit)
            if(!k) x=flip?!x:x,cnt.push_back(0);
            else if(x&&flip) k--,cnt.push_back(1);
            else if(!x&&!flip) x=!x,k--,cnt.push_back(1);
            else x=flip?!x:x,cnt.push_back(0);
        if(k) bit.back()=1^(k&1),cnt.back()+=k;
        for(auto x:bit) cout<<x;
        cout<<endl;
        for(auto x:cnt) cout<<x<<' ';
        cout<<endl;
    }
    return 0;
}