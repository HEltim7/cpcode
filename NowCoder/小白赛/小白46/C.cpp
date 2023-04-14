#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;
string s[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    LL ans=0;
    
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>s[i];
    map<string,int> mp;
    for(int l=0,r=1;r<=n;r++){
        if(r-l-2>k) mp.find(s[++l])->second--;
        ans+=mp[s[r]];
        if(mp.find(s[r])==mp.end()) mp.emplace(s[r],1);
        else mp[s[r]]++;
    }
    cout<<ans;
    return 0;
}