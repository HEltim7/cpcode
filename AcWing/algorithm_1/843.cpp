#include<iostream>
using namespace std;
int n;
char matrix[10][10];

bool check(int col,int l,int r,int h){
    int tmp=1<<(n-col);
    return !(tmp&(l|r|h));
}

void dfs(int deep,int l,int r,int h){
    if(deep>n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) cout<<matrix[i][j];
            cout<<'\n';
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=n;i++){
        if(check(i,l,r,h)){
            matrix[deep][i]='Q';
            int move=1<<(n-i);
            l+=move,r+=move,h+=move;
            dfs(deep+1,l>>1,r<<1,h);
            l-=move,r-=move,h-=move;
            matrix[deep][i]='.';
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) matrix[i][j]='.';
    dfs(1,0,0,0);
    return 0;
}