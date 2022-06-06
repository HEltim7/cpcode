#include<iostream>
#include<stack>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e6+10;
int v[N],dist[N],l[N],r[N];
struct SEG
{
    int end,root,size;
} ;
vector<SEG> stk;
int n,ans[N];

int merge(int x,int y){
    if(!x||!y) return x+y;
    if(v[x]<v[y]) swap(x,y);
    r[x]=merge(r[x],y);
    if(dist[r[x]]>dist[l[x]]) swap(l[x],r[x]);
    dist[x]=dist[r[x]]+1;
    return x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>v[i],v[i]-=i;
    for(int i=1;i<=n;i++){
        SEG cur={i,i,1};
        dist[i]=1;
        while(stk.size()&&v[cur.root]<v[stk.back().root]){
            cur.root=merge(cur.root,stk.back().root);
            if(cur.size%2&&stk.back().size%2)
                cur.root=merge(l[cur.root],r[cur.root]);
            cur.size+=stk.back().size;
            stk.pop_back();
        }
        stk.push_back(cur);
    }
    for(int i=0,j=1;i<stk.size();i++){
        while(j<=stk[i].end) ans[j++]=v[stk[i].root];
    }
    LL res=0;
    for(int i=1;i<=n;i++) res+=abs(v[i]-ans[i]);
    cout<<res<<endl;
    for(int i=1;i<=n;i++) cout<<ans[i]+i<<' ';
    return 0;
}