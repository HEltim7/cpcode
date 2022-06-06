#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<int> VI;
const int N=110;
int n,m;
int in[N];
VI ans;
VI adj[N];

bool topsort(){
    queue<int> q;
    for(int i=1;i<=n;i++) if(in[i]==0) q.push(i);
    while(q.size()){
        int h=q.front();
        ans.push_back(h);
        for(auto x:adj[h]){
            in[x]--;
            if(in[x]==0) q.push(x);
        }
        q.pop();
    }
    if(ans.size()==n) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        in[b]++;
    }
    if(topsort()){
        for(auto x:ans) cout<<x<<' ';
    }
    else cout<<"-1";
    return 0;
}