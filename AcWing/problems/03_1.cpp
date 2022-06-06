//三循环暴力版
#include<iostream>
using namespace std;
int N,V;
struct yuri
{
    int v;
    int w;
} item[1010];
int f[1010][1010];

int main(){
    cin>>N>>V;
    for(int i=1;i<=N;i++) scanf("%d%d",&item[i].v,&item[i].w);
    for(int i=1;i<=N;i++){
        for(int j=0;j<=V;j++){
            for(int k=0;k*item[i].v<=j;k++){
                f[i][j]=max(f[i][j],f[i-1][j-k*item[i].v]+k*item[i].w);
            }
        }
    }
    cout<<f[N][V];
    return 0;
}