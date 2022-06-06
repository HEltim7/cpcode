#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
int cnt[1<<7];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string in;
        cin>>in;
        for(auto x:in) cnt[x]++;
        string ans;
        for(char i='a';i<='z';i++)
            while(cnt[i]) ans.push_back(i),cnt[i]--;
        cout<<ans<<endl;
    }
    return 0;
}