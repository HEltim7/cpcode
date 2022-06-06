#include<iostream>
#include<algorithm>
using namespace std;
const int N=510;
const int M=1e5+10;
int skill[N][N];
bool all[M];
int may[N*N];
int n,cnt,maxx;

void check(int minn){
    bool mark[N][N]={0};
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(skill[i][j]<minn){
                mark[i][j]=1;
            }
        }
    }
    
    maxx=minn;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>skill[i][j];
            if(all[skill[i][j]]!=1){
                may[++cnt]=skill[i][j];
                all[skill[i][j]]=1;
            }
        }
    }
    sort(may+1,may+cnt+1);
    for(int i=1;i<=cnt;i++) check(may[i]);
    return 0;
}