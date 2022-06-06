#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
bool mark[26];

// #define __DEBUG
#ifdef __DEBUG
#include<debug>
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        memset(mark,0,sizeof mark);
        int n;
        cin>>n;
        string str;
        cin>>str;
        str=" "+str;
        int k;
        cin>>k;
        for(int i=1;i<=k;i++) {
            char in;
            cin>>in;
            mark[in-'a']=1;
        }
        vector<int> pos;
        pos.push_back(1);
        for(int i=1;i<str.size();i++){
            int cur=str[i]-'a';
            if(mark[cur]) pos.push_back(i);
        }
        debug(pos);
        int ans=0;
        for(int i=1;i<pos.size();i++){
            ans=max(ans,pos[i]-pos[i-1]);
        }
        cout<<ans<<endl;
    }
    return 0;
}