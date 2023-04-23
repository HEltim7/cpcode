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
        string a,b;
        cin>>a>>b;
        memset(cnt,0,sizeof cnt);
        bool ans=1;
        for(int i=a.size()-1,j=b.size()-1;j>=0;i--,j--){
            while(i>=0&&a[i]!=b[j]) cnt[a[i--]-'A']++;
            if(i<0||cnt[b[j]-'A']>0){
                ans=0;
                break;
            }
        }
        cout<<(ans?"YES":"NO")<<endl;
    }
    return 0;
}