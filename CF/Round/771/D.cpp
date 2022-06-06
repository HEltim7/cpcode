#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int,int> PII;
const int N=1e3+10;
int n,m;
int color[N][N];
int mvr[]={1,1,0,0};
int mvc[]={0,1,0,1};
int Round[]={-1,0,1};
bool pass[N][N];
struct ANS{
    int row,col,color;
};
vector<ANS> ans;

//判断越界
inline bool inboard(int row,int col){
    return row>=1&&row<n&&col>=1&&col<m&&!pass[row][col];
}

//取四格当中颜色最大的
inline int getmax(int row,int col){
    int maxx=0;
    for(int i=0;i<4;i++){
        int r=row+mvr[i];
        int c=col+mvc[i];
        maxx=max(maxx,color[r][c]);
    }
    return maxx;
}

//向右下绘制
//判断一个点是否可行，是否颜色除了0之外只有1种颜色
inline bool check(int row,int col){
    if(inboard(row,col)){
        int cnt=0,maxx=getmax(row,col);
        if(maxx==0) return 0;
        for(int i=0;i<4;i++){
            int r=row+mvr[i];
            int c=col+mvc[i];
            if(color[r][c]==maxx||color[r][c]==0) cnt++;
        }
        return cnt==4;
    }
    return 0;
}

//涂色，并判断周围一圈是否可更新，涂完之后颜色为0
inline void update(int row,int col,queue<PII> &q){
    pass[row][col]=1;
    ans.push_back({row,col,getmax(row,col)});
    for(int k=0;k<4;k++)
        color[row+mvr[k]][col+mvc[k]]=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            if(Round[i]||Round[j]){
                int r=row+Round[i];
                int c=col+Round[j];
                if(check(r,c)) q.push({r,c});
            }
        }
}

//debug用的，输出整个矩阵
// void cat(){
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++)
//             cout<<color[i][j]<<' ';
//         cout<<endl;
//     }
//     cout<<"-----"<<endl;
// }

//也是debug,检查最后效果
// void CAT(){
//     memset(color,0,sizeof color);
//     for(auto [a,b,c]:ans){
//         for(int i=0;i<4;i++)
//             color[a+mvr[i]][b+mvc[i]]=c;
//     }
//     cat();
// }

bool bfs(){
    queue<PII> q;
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            if(check(i,j))
                q.push({i,j});//先把4个连块的入队
    while(q.size()){
        auto [r,c]=q.front();
        q.pop();
        if(getmax(r,c)) update(r,c,q);
        // cat();
    }
    bool res=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(color[i][j]) res=0;//看看是否所有点都设0了
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>color[i][j];

    if(bfs()){
        cout<<ans.size()<<endl;
        reverse(ans.begin(),ans.end());
        // CAT();
        for(auto [a,b,c]:ans) cout<<a<<' '<<b<<' '<<c<<endl;
    }
    else cout<<-1;
    return 0;
}