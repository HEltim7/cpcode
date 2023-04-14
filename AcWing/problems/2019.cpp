#include<iostream>
#include<queue>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
const int N=1e3+10;
int n,x,y,maxx,maxy;
int dist[N][N];
bool matrix[N][N],passed[N][N];

inline bool check(int row,int col){
    return !passed[row][col]&&row>=0&&row<=maxx+1&&col>=0&&col<=maxy+1;
}

int bfs(){
    deque<PII> q;
    q.emplace_back(x,y);
    int mvr[]={0,1,-1,0,0};
    int mvc[]={0,0,0,1,-1};
    while(q.size()){
        auto [row,col]=q.front();
        if(row==0&&col==0) return dist[row][col];
        passed[row][col]=1;
        q.pop_front();
        for(int i=1;i<=4;i++){
            int r=row+mvr[i];
            int c=col+mvc[i];
            if(check(r,c)){
                if(matrix[r][c]) q.emplace_back(r,c);
                else q.emplace_front(r,c);
                dist[r][c]=dist[row][col]+matrix[r][c];
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>x>>y;
    int a,b;
    for(int i=1;i<=n;i++){
        cin>>a>>b,matrix[a][b]=1;
        maxx=max(maxx,a),maxy=max(maxy,b);
    }
    cout<<bfs();
    return 0;
}