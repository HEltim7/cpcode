#include<iostream>
#include<map>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e5+10;
LL a[N],ans;
map<int,int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]+=a[i-1];
    }
    mp.emplace(0,1);
    for(int r=1,l=0;r<=n;r++){
        if(r-l>=k) mp[(a[l]-l++)%k]--;
        LL cur=(a[r]-r)%k;
        if(mp.find(cur)!=mp.end()) ans+=mp[cur]++;
        else mp.emplace(cur,1);
    }
    cout<<ans;
    return 0;
}