#include<iostream>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int,int> PII;
set<PII> s[2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    s[0].insert({1,2}),s[0].insert({2,3}),s[0].insert({3,1});
    s[1].insert({1,3}),s[1].insert({3,2}),s[1].insert({2,1});
    int ans[2]={0};
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(s[0].find({a,b})!=s[0].end()) ans[0]++;
        if(s[1].find({a,b})!=s[1].end()) ans[1]++;
    }
    cout<<max(ans[0],ans[1]);
    return 0;
}