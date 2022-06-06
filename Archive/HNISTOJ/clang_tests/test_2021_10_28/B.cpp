#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
const int N=110;

PII tv[N];

bool cmp(PII a,PII b){
    if(a.second==b.second) return a.first>b.first;
    return a.second<b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    while(cin>>n&&n){
        int ans=0,t=0;
        for(int i=1;i<=n;i++) cin>>tv[i].first>>tv[i].second;
        sort(tv+1,tv+n+1,cmp);
        for(int i=1;i<=n;i++) if(tv[i].first>=t) t=tv[i].second,ans++;
        cout<<ans<<endl;
    }
    return 0;
}