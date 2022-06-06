#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
const int N=2e5*2+10;
int e[N],ne[N],w[N],h[N],idx;
bool mark[N];

inline void add(int a,int b,int c){
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
    e[idx]=a,ne[idx]=h[b],w[idx]=c,h[b]=idx++;
}

inline bool check(int x,int bit){
    return x&(1<<bit);
}

void dfs(int root,int bit){
    mark[root]=1;
    for(int i=h[root];~i;i=ne[i]){
        int ver=e[i];
        if(mark[ver]||!ver||check(w[i],bit)) continue;
        dfs(ver,bit);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(h,-1,sizeof (int)*(n+1));
        idx=0;
        int ans=0;
        for(int i=1;i<=m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            add(a,b,c);
        }
        for(int i=29;i>=0;i--){
            memset(mark,0,sizeof (bool)*(n+1));
            dfs(1,i);
            bool res=1;
            for(int j=1;j<=n;j++) if(!mark[j]){
                res=0;
                break;
            }
            if(res){
                for(int j=0;j<idx;j++) if(check(w[j],i)) e[j]=0;
            }
            else ans+=1<<i;
        }
        cout<<ans<<endl;
    }
    return 0;
}