#include<iostream>
using namespace std;

#define endl '\n'

const int N=10;
bool matrix[N][N];
bool pass[N][N];
int res[N][N];
int n,ans;
int mvr[]={0,1,-1,0,0};
int mvc[]={0,0,0,1,-1};

inline bool check(int row,int col,int state){
    return !pass[row][col]
            &&row>=1&&row<=n&&col>=1&&col<=n
            &&matrix[row][col]==state;
}

int dfs0(int row,int col){
    int tmp=0;
    pass[row][col]=1;
    for(int i=1;i<=4;i++){
        int r=row+mvr[i];
        int c=col+mvc[i];
        if(check(r,c,0)) tmp=max(tmp,dfs0(r,c));
    }
    pass[row][col]=0;
    return tmp+1;
}

void dfs(int row,int col,int cnt){
    pass[row][col]=1;
    for(int i=1;i<=4;i++){
        int r=row+mvr[i];
        int c=col+mvc[i];
        if(check(r,c,1)) dfs(r,c,cnt+1);
        else if(check(r,c,0)){
            if(cnt>ans){
                if(!res[r][c]) res[r][c]=dfs0(r,c);
                if(cnt<=res[r][c]) ans=max(ans,cnt);
            }
        }
    }
    pass[row][col]=0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char in;
            cin>>in;
            if(in=='(') matrix[i][j]=1;
        }
    }
    if(matrix[1][1]) dfs(1,1,1);
    cout<<ans*2;
    return 0;
}