#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e3+10;
int grid[N*N];
int n,m;

inline int getid(int r,int c){
    return (c-1)*n+r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int q,cnt=0,res=0;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            grid[getid(i,j)]=c=='*';
            cnt+=c=='*';
        }
    for(int i=1;i<=getid(n,m);i++)
        if(grid[i])
            res+=i>cnt;
        
    while(q--){
        int row,col;
        cin>>row>>col;
        int cur=getid(row,col);
        if(grid[cur]){ //remove
            if(grid[cnt]) res++;
            cnt--;
            res-=cur>cnt;
            grid[cur]=0;
        }
        else{ //add
            grid[cur]=1;
            res+=cur>cnt;
            cnt++;
            if(grid[cnt]) res--;
        }
        cout<<res<<endl;
    }
    return 0;
}