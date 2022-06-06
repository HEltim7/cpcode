#include<iostream>
using namespace std;

const int N=1e3+10;
typedef long long ll;
ll matrix[N][N],diff[N][N];

void insert(int r,int c,int rr,int cc,int val){
    diff[r][c]+=val;
    diff[rr+1][c]-=val;
    diff[r][cc+1]-=val;
    diff[rr+1][cc+1]+=val;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m,q;
    int r,c,rr,cc,val;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>matrix[i][j];
            insert(i,j,i,j,matrix[i][j]);
        }
    }
    for(int i=1;i<=q;i++){
        cin>>r>>c>>rr>>cc>>val;
        insert(r,c,rr,cc,val);
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) diff[i][j]+=diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cout<<diff[i][j]<<' ';
        cout<<'\n';
    }
    return 0;
}