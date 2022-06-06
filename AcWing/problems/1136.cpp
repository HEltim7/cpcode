#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=110,INF=0x3f3f3f3f;
typedef pair<int,int> PII;
bool pass[N][N],st[N][N];
int dist[N][N],matrix[N][N];
int n,k,A,B,C;
priority_queue<PII,vector<PII>,greater<PII>> heap;

inline int get(int x,int y){
    return x*n+y-1;
}

inline bool check(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=n&&!pass[x][y];
}

inline int cal(int x,int y){
    return (n-x+n-y)/k*A+dist[x][y];
}

void bfs(int row,int col){
    int mvr[]={0,-1,0,0,1};
    int mvc[]={0,0,-1,1,0};
    int fee[]={0,B,B,0,0};
    memset(pass,0,sizeof pass);
    queue<PII> q;
    q.push({0,get(row,col)});
    pass[row][col]=1;
    while(q.size()){
        auto [cost,x]=q.front();
        int y=x%n+1;
        x/=n;
        q.pop();
        
        //若遇到加油站/走了k步就停止
        if(!(x==row&&y==col)&&
            (x==n&&y==n||matrix[x][y]||abs(x-row)+abs(y-col)==k)){
            if(matrix[x][y]) cost+=A;
            else if(x!=n||y!=n) cost+=C+A;
            if(dist[x][y]>dist[row][col]+cost){
                dist[x][y]=dist[row][col]+cost;
                heap.push({cal(x,y),get(x,y)});
            }
            continue;
        }
        
        for(int i=1;i<=4;i++){
            int r=x+mvr[i];
            int c=y+mvc[i];
            if(check(r,c)) q.push({cost+fee[i],get(r,c)}),pass[r][c]=1;
        }
    }
    return ;
}

int a_star(){
    heap.push({0,get(1,1)});
    memset(dist,0x3f,sizeof dist);
    dist[1][1]=0;
    while(heap.size()){
        auto [dis,x]=heap.top();
        heap.pop();
        int y=x%n+1;
        x/=n;
        if(x==n&&y==n) return dist[x][y];
        if(!st[x][y])bfs(x,y);
        st[x][y]=1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k>>A>>B>>C;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>matrix[i][j];
    cout<<a_star();
    return 0;
}