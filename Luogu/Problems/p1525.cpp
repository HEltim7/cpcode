/*
    P1525 关押罪犯
    种类并查集
    https://zhuanlan.zhihu.com/p/97813717
*/
#include<iostream>
#include<algorithm>
using namespace std;
long n,m,fa[20010],ranks[20010];

struct data{
    int a;
    int b;
    long san;
};
data relation[100010];

bool cmp(data in1,data in2){
    return in1.san>in2.san;
}

int find(int in){
    return fa[in]==in?in:(fa[in]=find(fa[in]));
}

void merge(int a,int b){
    a=fa[find(fa[a])];
    b=fa[find(fa[b])];

    if(ranks[a]<ranks[b]){
        fa[a]=fa[b];
    }
    else if(ranks[a]>ranks[b]){
        fa[b]=fa[a];
    }
    else{
        fa[b]=fa[a];
        ranks[a]++;
    }
}

void init(){
    for(int i=1;i<=2*n;i++){
        fa[i]=i;
        ranks[i]=1;
    }
}

int main(){
    cin>>n>>m;
    init();
    for(int i=1;i<=m;i++){
        scanf("%d%d%ld",&relation[i].a,&relation[i].b,&relation[i].san);
    }
    sort(relation+1,relation+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(find(relation[i].a)==find(relation[i].b)){
            cout<<relation[i].san;
            return 0;
        }
        else{
            merge(relation[i].a,relation[i].b+n);
            merge(relation[i].b,relation[i].a+n);
        }
        
    }
    cout<<'0';
    return 0;
}