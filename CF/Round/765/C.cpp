#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
const int N=510;
typedef pair<int,int> PII;
vector<PII> sign;
int ans,n,l,k;
int loc[N],speed[N],fa[N],son[N];
typedef long long LL;

inline void update(){
    sign.clear();
    for(int i=1;i<=n;i=son[i]){
        if(i==1) continue;
        sign.emplace_back((speed[fa[i]]-speed[i])*(loc[son[i]]-loc[i]),i);
    }
    sort(sign.begin(),sign.end());
}

inline void del(int x){
    son[fa[x]]=son[x];
    fa[son[x]]=fa[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>l>>k;
    loc[n+1]=l;
    for(int i=1;i<=n;i++) cin>>loc[i];
    for(int i=1;i<=n;i++){
        cin>>speed[i];
        ans+=speed[i]*(loc[i+1]-loc[i]);
        fa[i]=i-1;
        son[i]=i+1;
    }
    for(int i=1;i<=k;i++){
        update();
        auto [res,id]=sign[0];
        if(res>0) break;
        ans+=res;
        del(id);
    }
    cout<<ans;
    return 0;
}

/*
5 10 2
0 3 5 7 8   
5 4 6 3 2
*/