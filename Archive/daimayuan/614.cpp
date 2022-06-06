#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
const int N=3e3+10;

int tr[N*2][N],pre[N][N];
bool grid[N][N];
int n,m;
LL ans;
vector<pair<int,int>> del[N*2];

inline void add(int row,int col,int val){
    int aim=row+col;
    while(col<N) tr[aim][col]+=val,col+=lowbit(col);
}

inline int __query(int aim,int pos){
    int res=0;
    while(pos) res+=tr[aim][pos],pos-=lowbit(pos);
    return res;
}

inline int query(int row,int col,int colr){
    int aim=row+col;
    return __query(aim,colr)-__query(aim,col-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char z;
            cin>>z;
            grid[i][j]=z=='z';
            ans+=z=='z';
        }

    for(int i=1;i<=n;i++){
        for(auto [r,c]:del[i]) add(r,c,-1);

        for(int j=1;j<=m;j++)
            for(int k=j;grid[i][k];k++){
                pre[i][k]=pre[i-1][k+1]+1;
                if(grid[i][k+1]==0){
                    int tmp=j;
                    while(j<k) {
                        int len=k-j+1;
                        ans+=query(i,j,j+min(pre[i][j],len)-1);
                        j++;
                    }
                    for(int t=tmp+1;t<=k;t++) {
                        add(i,t,1);
                        if(tmp>1) del[i+t-tmp+1].emplace_back(i,t);
                    }
                }
            }
    }
    cout<<ans;
    return 0;
}