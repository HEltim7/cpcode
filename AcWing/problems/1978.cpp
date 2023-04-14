#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
typedef vector<PII> VII;
VII cow;
stack<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        cow.emplace_back(a,b);
    }
    sort(cow.begin(),cow.end());
    int maxx=-1e6-1;
    for(auto [a,b]:cow){
        if(b>maxx) ans.push(b);
        else while(ans.size()&&b<ans.top()) ans.pop();
        maxx=max(maxx,b);
    }
    cout<<ans.size();
    return 0;
}