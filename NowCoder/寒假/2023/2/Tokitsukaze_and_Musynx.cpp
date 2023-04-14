#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
LL arr[N],ln[10],val[10];
queue<LL> q[10];

void solve() {
    int n;
    cin>>n;
    LL maxx=0;
    for(int i=1;i<=n;i++) cin>>arr[i],maxx=max(maxx,arr[i]);
    for(int i=1;i<=4;i++) cin>>ln[i];
    for(int i=1;i<=5;i++) cin>>val[i];
    ln[4]++;
    for(int i=1;i<=n;i++) arr[i]-=maxx-ln[1]+1;
    for(int i=1;i<=5;i++) while(q[i].size()) q[i].pop();

    auto get=[](LL x) {
        for(int i=1;i<=4;i++) if(x<ln[i]) return i;
        return 5;
    };

    LL sum=0,ans=0;
    multimap<LL,int> mp;
    sort(arr+1,arr+1+n,greater<>());
    for(int i=1;i<=n;i++) {
        ans+=val[get(arr[i])];
        q[get(arr[i])].push(arr[i]);
    }
    
    LL cur=ans;
    while(q[5].size()!=n) {
        mp.clear();
        for(int i=1;i<=4;i++)
            if(q[i].size()) 
                mp.emplace(ln[i]-q[i].front()-sum,i);

        auto [add,idx]=*mp.begin();
        sum+=add;
        for(int i=1;i<=4;i++) {
            while(q[i].size()&&q[i].front()+sum>=ln[i]) {
                q[i+1].push(q[i].front());
                cur=cur-val[i]+val[i+1];
                q[i].pop();
            }
        }
        ans=max(ans,cur);
    }

    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}