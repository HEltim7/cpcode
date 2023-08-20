#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int N= 100, D=50;
int n,vis[N][N],ok[N][N];
int ed[N][N];
vector<pair<int,int>> a;

void dfs(int x,int y,int id) {
    ok[x+D][y+D]++;
    if(id>=a.size()) {
        ed[x+D][y+D]=true;
        ok[x+D][y+D]--;
        return;
    }    
    auto [dx,dy]=a[id];
    int nx=x+dx;
    int ny=y+dy;
    if(vis[nx+D][ny+D]) {
        dfs(x,y,id+1);
    }else {
        dfs(nx,ny,id+1);
        if(!ok[nx+D][ny+D]) {
            vis[nx+D][ny+D]=1;
            dfs(x,y,id+1);
            vis[nx+D][ny+D]=0;
        }
    }
    ok[x+D][y+D]--;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; ++i) {
        char c;
        cin>>c;
        if(c=='L') a.emplace_back(-1,0);
        if(c=='D') a.emplace_back(0,-1);
        if(c=='R') a.emplace_back(1,0);
        if(c=='U') a.emplace_back(0,1);
    }
    dfs(0,0,0);
    vector<pair<int,int>> ans;
    for(int i=0; i<N; ++i)
        for(int j=0; j<N; ++j)
            if(ed[i][j])
                ans.emplace_back(i-D,j-D);
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto [x,y]:ans) cout<<x<<' '<<y<<"\n";
    return 0;
}