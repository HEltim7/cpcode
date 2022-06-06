#include<iostream>
#include<cstring>
using namespace std;
const int N=12;
int n;
int skill[N][N];
int maxx=0;
bool isok[N];

void dfs(int man,int sum){
    if(man>n){
        maxx=max(sum,maxx);
        return;
    }
    for(int i=1;i<=n;i++){
        if(isok[i]){
            isok[i]=0;
            dfs(man+1,sum+skill[man][i]);
            isok[i]=1;
        }
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>skill[i][j];
        }
    }
    memset(isok,1,sizeof(isok));   
    dfs(1,0);
    cout<<maxx;
    return 0;
}