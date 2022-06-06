#include<bits/stdc++.h>
using namespace std;
int m,n,z,x,y,fa[10010];
///////////////////////////////////
int getfa(int in){
    if(fa[in]==in){return in;}
    return fa[in]=getfa(fa[in]);
}
///////////////////////////////////
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){fa[i]=i;}
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&z,&x,&y);
        if(z==1){
            fa[getfa(x)]=getfa(y);
        }
        else{
            if(getfa(x)==getfa(y)){
                printf("Y\n");
            }
            else{
                printf("N\n");
            }
        }
    }
}