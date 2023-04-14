#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<PII> VII;

VII cow;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(int i=0;i<30;i++) cow.push_back({-1,-1});
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        int t=s[i]-'A';
        if(cow[t].first==-1) cow[t].first=i;
        else cow[t].second=i;
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++){
            if(i==j) continue;
            auto [a,b]=cow[i];
            auto [c,d]=cow[j];
            if(c>a&&c<b&&d>b) ans++;
        }
    }
    cout<<ans;
    return 0;
}