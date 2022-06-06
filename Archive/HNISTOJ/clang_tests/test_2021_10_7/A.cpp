#include<iostream>
using namespace std;

const int N=110;
bool mark[N];
int num[N];
int idx,n;

void dfs(int deep){
    if(deep>n){
        for(int i=1;i<=n;i++) cout<<num[i]<<' ';
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!mark[i]){
            mark[i]=1;
            num[++idx]=i;
            dfs(deep+1);
            idx--;
            mark[i]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    dfs(1);
    return 0;
}