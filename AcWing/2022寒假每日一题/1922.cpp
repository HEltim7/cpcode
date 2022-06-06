#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
const int N=1e6+10;
typedef pair<int,int> PII;
PII grass[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k,ans=0,res=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>grass[i].second>>grass[i].first;
    sort(grass+1,grass+1+n);
    for(int i=1,j=1;i<=n;i++){
        res+=grass[i].second;
        while(grass[i].first-grass[j].first>2*k) res-=grass[j++].second;
        ans=max(ans,res);
    }
    cout<<ans;
    return 0;
}