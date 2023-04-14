#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int N=501000;
int way[2][N+1];
int n,k;
int ans;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        memset(way,0,sizeof way);
        for(int i=-n;i<=n;i++){
            for(int j=-n;j<=n;j++){
                int res=i*(i+1)+j*(j+1);
                if(res>0) way[1][res]++;
                else way[0][-res]++;
            }
        }

        int maxx=n*(n+1)*2;
        if(k<0){
            for(int i=1;i<=maxx;i++){
                if(i%k!=0) continue;
                int aim=abs(i/k);
                ans+=way[0][i]*way[0][aim];
            }
            for(int i=-maxx;i<=0;i++){
                if(i%k!=0) continue;
                int aim=abs(i/k);
                ans+=way[1][-i]*way[1][aim];
            }
        }
        else if(k>0){
            for(int i=1;i<=maxx;i++){
                if(i%k!=0) continue;
                int aim=abs(i/k);
                ans+=way[1][i]*way[1][aim];
            }
            for(int i=-maxx;i<=0;i++){
                if(i%k!=0) continue;
                int aim=abs(i/k);
                ans+=way[0][-i]*way[0][aim];
            }
        }
        else{
            for(int i=1;i<=maxx;i++){
                int aim=0;
                ans+=way[1][i]*way[1][aim];
            }
            for(int i=-maxx;i<=0;i++){
                int aim=0;
                ans+=way[0][-i]*way[0][aim];
            }
        }
        printf("%d\n",ans);
        ans=0;
    }

    return 0;
}