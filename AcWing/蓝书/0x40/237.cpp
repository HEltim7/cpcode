#include<iostream>
#include<cstring>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

#define endl '\n'
#define get(x) (lower_bound(num.begin(),num.end(),x)-num.begin())
typedef long long LL;
const int N=2e5+10;
int fa[N],rk[N];

int findfa(int x){
    if(fa[x]==x) return x;
    return fa[x]=findfa(fa[x]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,i,j,e;
        cin>>n;
        vector<pair<int,int>> unequ,equ;
        vector<int> num;
        while(n--){
            cin>>i>>j>>e;
            num.push_back(i),num.push_back(j);
            if(e==1) equ.emplace_back(i,j);
            else unequ.emplace_back(i,j);
        }
        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());
        iota(fa,fa+num.size(),0);
        iota(rk,rk+num.size(),1);

        for(auto [a,b]:equ){
            a=get(a),b=get(b);
            a=findfa(a),b=findfa(b);
            if(rk[a]<rk[b]) swap(a,b);
            fa[b]=a,rk[a]+=rk[b];
        }
        bool ans=1;
        for(auto [a,b]:unequ){
            a=get(a),b=get(b);
            a=findfa(a),b=findfa(b);
            if(a==b) ans=0;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}