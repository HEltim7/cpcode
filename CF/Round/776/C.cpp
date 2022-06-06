#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<LL,LL> PII;
const int N=2e5+10;
struct DATA
{
    int idx,w,id;
} p[N];

bool cmp(DATA &a,DATA &b){
    return a.w<b.w;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            cin>>p[i].idx>>p[i].w;
            p[i].id=i;
        }
        sort(p+1,p+1+m,cmp);
        vector<PII> tmp;
        LL ans=0;
        for(int i=1;i<=2*n;i++) ans+=p[i].w,tmp.push_back({p[i].idx,p[i].id});
        sort(tmp.begin(),tmp.end());
        cout<<ans<<endl;
        for(int i=0,j=tmp.size()-1;i<j;i++,j--)
            cout<<tmp[i].second<<' '<<tmp[j].second<<endl;
    }
    return 0;
}