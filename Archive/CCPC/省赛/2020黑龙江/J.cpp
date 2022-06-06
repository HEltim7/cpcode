#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
const LL N=3e5+10;
vector<LL> dis;
LL a[N],b[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,t;
    cin>>t;
    while(t--){
        LL ans=0;
        dis.clear();
        cin>>n;
        for(int i=1;i<=n;i++){
            a[i]=i;
            cin>>b[i];
            dis.push_back(a[i]*a[i]+b[i]*b[i]);
        }
        sort(dis.begin(),dis.end());
        ans=dis[n-1]-dis[0];
        
        dis.clear();

        for(int i=1;i<=n;i++){
            LL v=N*N;
            dis.push_back(b[i]*b[i]+(v-a[i]*a[i]));
        }
        sort(dis.begin(),dis.end());
        ans=max(ans,dis[n-1]-dis[0]);
        cout<<ans<<endl;
    }
    return 0;
}