#include <iostream>
#include <bitset>
#include <queue>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
#define fi first
#define se second

const int N=510;
bool state[N][N];
int n,m,q;

struct quenode
{
    int row;
    int col;
    int state;
};


typedef pair<int,int> PII;

queue<quenode> que;

bool check(int row,int col){
    if(row>n||col>m) return 0;
    if(state[row][col]!=0) return 0;
    return 1;
}

void bfs(){
    if(que.empty()) return;
    quenode p=que.front();
    if(check(p.row+1,p.col)){
        p.row+=1;
        // p=
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int r,c;
            cin>>r>>c;
            state[r][c]=-1;
        }
    }

    for(int r=1;r<=n;r++){
        for(int c=1;c<=m;c++){
            if(state[r][c]==0){
                state[r][c]=1;
                for(int i=r;i<=n;i++){
                    for(int j=c;j<=m;j++){
                        if(i==r&&j==c) continue;
                        state[i][j]=max(state[i-1][j],state[i][j-1])+1;
                    }
                }
            }
        }
    }
}