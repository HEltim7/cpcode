#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    vector<LL> l,r;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        l.push_back(a);
        r.push_back(b);
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    LL ans=0;
    for(int i=0;i<l.size();i++) ans+=max(l[i],r[i]);
    cout<<ans+l.size();
    return 0;
}