#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    vector<LL> v;
    for(int i=1;i<=n;i++) {
        LL r;
        cin>>r;
        v.push_back(r*r);
    }
    sort(v.begin(),v.end());
    while(q--){
        LL x,y;
        cin>>x>>y;
        LL t=x*x+y*y;
        cout<<upper_bound(v.begin(),v.end(),t)-v.begin()<<endl;
    }
    return 0;
}