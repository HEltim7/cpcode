//滚动数组优化版
#include<iostream>
using namespace std;
int N,V;
struct yuri
{
    int v;
    int w;
} item[1010];
int f[1010];

int main(){
    cin>>N>>V;
    for(int i=1;i<=N;i++) scanf("%d%d",&item[i].v,&item[i].w);
    for (int i = 1; i <= N; i++){
        for(int j=V;j>=item[i].v;j--){
            f[j]=max(f[j],f[j-item[i].v]+item[i].w);
        }
    }
    cout<<f[V];
    return 0;
}