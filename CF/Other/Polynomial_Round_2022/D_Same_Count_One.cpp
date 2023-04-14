#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int cnt[N];
vector<int> arr[N];

void solve() {
    int n,m,tot=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) arr[i].resize(m+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            cin>>arr[i][j];
            if(arr[i][j]) cnt[i]++,tot++;
        }
    if(tot%n) cout<<-1<<endl;
    else {
        int ans=0,per=tot/n;
        for(int i=1;i<=n;i++) ans+=abs(cnt[i]-per);
        cout<<ans/2<<endl;

        vector<int> more,less;
        for(int j=1;j<=m;j++) {
            more.clear();
            less.clear();
            for(int i=1;i<=n;i++) {
                if(cnt[i]<per&&arr[i][j]==0) less.push_back(i);
                if(cnt[i]>per&&arr[i][j]==1) more.push_back(i);
            }
            while(less.size()&&more.size()) {
                int x=less.back();
                int y=more.back();
                cout<<x<<' '<<y<<' '<<j<<endl;
                cnt[x]++;
                cnt[y]--;
                less.pop_back();
                more.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}