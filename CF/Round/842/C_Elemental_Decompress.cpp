#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int res[2][N];
pair<int,int> arr[N];

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i].first,arr[i].second=i;
    set<int> st[2];
    for(int i=1;i<=n;i++) st[0].insert(i),st[1].insert(i);
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i++) {
        auto [x,id]=arr[i];
        bool flag=0;
        for(int j=0;j<2;j++) {
            if(st[j].count(x)&&*st[j^1].begin()<=x) {
                res[j][id]=x;
                res[j^1][id]=*st[j^1].begin();
                st[j].erase(x);
                st[j^1].erase(st[j^1].begin());
                flag=1;
                break;
            }
        }
        if(!flag) {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++) cout<<res[0][i]<<" \n"[i==n];
    for(int i=1;i<=n;i++) cout<<res[1][i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}