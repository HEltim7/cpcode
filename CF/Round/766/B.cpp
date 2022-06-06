#include<iostream>
#include<queue>
#include<cstring>
#include<set>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
const int N=2e5+10;

struct NODE{
    int row,col,step;
};

int ans[N];

void bfs(int n,int m){
    memset(ans,0,sizeof (int)*(n+m+1));
    set<PII> pass;
    int r=(n+1)/2;
    int c=(m+1)/2;
    int dis=abs(n-r)+abs(m-c);
    queue<NODE> q;
    if(n%2&&m%2) q.push({r,c,0});
    else if(n%2==0&&m%2==0)q.push({r,c,0}),q.push({r+1,c,0}),q.push({r,c+1,0}),q.push({r+1,c+1,0});
    else if(n%2==0) q.push({r,c,0}),q.push({r+1,c,0});
    else if(m%2==0) q.push({r,c,0}),q.push({r,c+1,0});
    int mvr[]={1,-1,0,0};
    int mvc[]={0,0,1,-1};
    while(q.size()){
        auto [row,col,step]=q.front();
        q.pop();
        if(pass.find({row,col})!=pass.end()) continue;
        ans[step]++;
        pass.insert({row,col});
        for(int i=0;i<4;i++){
            int x=row+mvr[i];
            int y=col+mvc[i];
            if(x>=1&&x<=n&&y>=1&&y<=m) q.push({x,y,step+1});
        }
    }
    int idx=0;
    for(int i=0;i<n*m;i++){
        cout<<dis<<' ';
        ans[idx]--;
        if(ans[idx]==0) idx++,dis++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        bfs(n,m);
        cout<<endl;
    }
}