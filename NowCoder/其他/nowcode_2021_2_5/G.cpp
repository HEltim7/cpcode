#include<bits/stdc++.h>
using namespace std;
struct fa_data{
    long fa;
    long wanna;
} fa[1000010];
long m,n;
unsigned long long sum;
fa_data getfa(long in){
    if(fa[in].fa==in)return {in,fa[in].wanna};
    return fa[in]=getfa(fa[in].fa);
}

int  main(){
    cin>>n>>m;
    for(long i=1;i<=n;i++){
        scanf("%ld",&fa[i].wanna);
        fa[i].fa=i;
    }
    long a,b;
    for(long i=1;i<=m;i++){
        scanf("%ld%ld",&a,&b);
        if(getfa(a).wanna>getfa(b).wanna){
            fa[getfa(b).fa]=getfa(a);
        }
        else{
            fa[getfa(a).fa]=getfa(b);
        }
    }
    for(long i=1;i<=n;i++){
        sum+=getfa(i).wanna;
    }
    cout<<sum;
    return 0;
}