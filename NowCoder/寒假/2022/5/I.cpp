#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e6+10;
set<LL> sleep;
LL n,q;
LL num[N];
LL pre[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    vector<LL> res;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=2;i<=n;i++) res.push_back(num[i]-num[i-1]);
    sort(res.begin(),res.end());
    for(int i=0;i<res.size();i++) pre[i+1]=pre[i]+res[i];
    while(q--){
        LL k,t;
        cin>>k>>t;
        int x=lower_bound(res.begin(),res.end(),k)-res.begin()+1;
        if(pre[n-1]-pre[x-1]-(n-x)*k>=t) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
////////////////////