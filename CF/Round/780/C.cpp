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
        memset(cnt,0,sizeof cnt);
        string s;
        cin>>s;
        int n=s.size();
        int ans=0;
        for(int i=0,j=-1;i<s.size();i++){
            cnt[s[i]]++;
            if(cnt[s[i]]>=2){
                while(j<i) cnt[s[++j]]--;
                ans+=2;
            }
        }
        cout<<n-ans<<endl;
    }
    return 0;
}