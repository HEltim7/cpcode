#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
int cnt[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        memset(cnt,0,sizeof cnt);
        string in;
        cin>>in;
        int idx=in.size()-1;
        for(int i=in.size()-1;i>=0;i--){
            cnt[in[i]-'a']++;
            if(cnt[in[i]-'a']==1) idx=i;
        }
        for(int i=idx;i<in.size();i++) cout<<in[i];
        cout<<endl;
    }
    return 0;
}