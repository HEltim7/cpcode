//P3368 【模板】树状数组 1
#include<cstdio>
#include<cstring>
#define lowbit(x) x&(-x)
unsigned int n,m,mth;
int BIT[500050];

inline void update(long a,long b){
    while(a<=n){
        BIT[a]+=b;
        a+=lowbit(a);
    }
}

inline long query(long in){
    long ans=0;
    for(;in;in-=lowbit(in)){
        ans+=BIT[in];
    }
    return ans;
}

inline long query(long a,long b){
    return query(b)-query(a-1);
}

int main(){
    long a,b;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&b);
        update(i,b);
    }
    for(int i=1;i<=m;i++){
        scanf("%d%ld%ld",&mth,&a,&b);
        if(mth==1){
            update(a,b);
        }
        if(mth==2){
            printf("%ld\n",query(a,b)) ;
        }
    }
    return 0;
}