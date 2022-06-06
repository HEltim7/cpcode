#include<iostream>
#include<cmath>
using namespace std;
const int N=1e5+10;
int son[N*31][2];
int cnt[N*31];
int n,idx;

void insert(int in){
    int num[31]={0},i=30;
    int now=0;
    while(in&&i>=0){
        if(in%2==1) num[i]=1;
        else num[i]=0;
        i--;
        in/=2;
    }
    for(i=0;i<31;i++){
        if(!son[now][num[i]]) son[now][num[i]]=++idx;
        now=son[now][num[i]];
    }
    cnt[now]++;
}

int dfs(int lnow,int rnow,int deep,int res){
    if(deep>=31) return res;
    if(son[lnow][0]&&son[rnow][1]&&son[lnow][1]&&son[rnow][0]){
        res+=pow(2,30-deep);
        int lmax=dfs(son[lnow][0],son[rnow][1],deep+1,res);
        int rmax=dfs(son[lnow][1],son[rnow][0],deep+1,res);
        res=max(lmax,rmax);
    }
    else if(son[lnow][0]&&son[rnow][1]){
        res+=pow(2,30-deep);
        res=dfs(son[lnow][0],son[rnow][1],deep+1,res);
    }
    else if(son[lnow][1]&&son[rnow][0]){
        res+=pow(2,30-deep);
        res=dfs(son[lnow][1],son[rnow][0],deep+1,res);
    }
    else if(son[lnow][0]){
        res=dfs(son[lnow][0],son[rnow][0],deep+1,res);
    }
    else
        res=dfs(son[lnow][1],son[rnow][1],deep+1,res);
    return res;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n;
    int tmp;
    while(n--){
        cin>>tmp;
        insert(tmp);
    }
    cout<<dfs(0,0,0,0);
    return 0;
}