#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    map<int,int> mp;
    int q;
    cin>>q;
    while(q--){
        int op,x,c;
        cin>>op;
        if(op==1) {
            cin>>x;
            auto it=mp.find(x);
            if(it==mp.end()) mp.emplace(x,1);
            else it->second++;
        }
        else if(op==2) {
            cin>>x>>c;
            auto it=mp.find(x);
            if(it->second<=c) mp.erase(x);
            else it->second-=c;
        }
        else{
            cout<<mp.rbegin()->first-mp.begin()->first<<endl;
        }
    }
    return 0;
}