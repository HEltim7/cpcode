#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

using LL=long long;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    vector<pair<int,char>> pre;
    string ans;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        bool flag=0;
        if(pre.size()) {
            int l=0,r=pre.size()-1;
            while(l<r) {
                int mid=l+r>>1;
                cout<<"? 2 "<<pre[mid].first<<' '<<i<<endl;
                int in;
                cin>>in;
                if(in==mid+1) r=mid,flag=1;
                else l=mid+1;
            }
            cout<<"? 2 "<<pre[l].first<<' '<<i<<endl;
            int in;
            cin>>in;
            if(in==l+1) flag=1;
            if(flag) ans.push_back(pre[l].second),pre.erase(next(pre.begin(),l));
        }
        if(!flag) {
            cout<<"? 1 "<<i<<endl;
            char in;
            cin>>in;
            ans.push_back(in);
        }
        pre.emplace_back(i,ans.back());
        sort(pre.begin(),pre.end(),greater<pair<int,char>>());
        debug(ans,pre);
    }
    cout<<"! "<<ans;
    return 0;
}