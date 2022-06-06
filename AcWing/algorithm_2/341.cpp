#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

typedef vector<int> VI;
const int N=1e5+10;

int dmin[N],dmax[N];
int n,m;
VI adj[N],adr[N];
int val[N];
bool inque[N];

void spfa(){
    queue<int> q;
    memset(dmin,0x3f,sizeof dmin);
    dmin[1]=val[1];
    inque[1]=1;
    q.push(1);

    while(q.size()){
        int h=q.front();
        q.pop();
        inque[h]=0;
        for(auto x:adj[h]){
            if(dmin[x]>min(val[x],dmin[h])){
                dmin[x]=min(val[x],dmin[h]);
                if(!inque[x]) q.push(x);
                inque[x]=1;
            }
        }
    }
}

void spfa_reverse(){
    queue<int> q;
    memset(dmax,0xcf,sizeof dmax);
    dmax[n]=val[n];
    inque[n]=1;
    q.push(n);

    while(q.size()){
        int h=q.front();
        q.pop();
        inque[h]=0;
        for(auto x:adr[h]){
            if(dmax[x]<max(val[x],dmax[h])){
                dmax[x]=max(val[x],dmax[h]);
                if(!inque[x]) q.push(x);
                inque[x]=1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>val[i];
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(c==1) adj[a].push_back(b),adr[b].push_back(a);
        else{
            adj[a].push_back(b),adj[b].push_back(a);
            adr[a].push_back(b),adr[b].push_back(a);
        }
    }
    spfa(),spfa_reverse();
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dmax[i]-dmin[i]);
    cout<<ans;
    return 0;
}