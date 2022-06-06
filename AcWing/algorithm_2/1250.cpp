#include<iostream>
using namespace std;

const int N=50010;
int n,m;
int fa[N];

int findfa(int x){
    if(fa[x]==x) return x;
    else return fa[x]=findfa(fa[x]);
}

int get(int row,int col){
    return (row-1)*n+col;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<N;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        int row,col;
        char dir;
        cin>>row>>col>>dir;
        int idx=get(row,col);
        if(dir=='D'){
            if(findfa(idx)==findfa(get(row+1,col))){
                cout<<i;
                return 0;
            }
            else fa[get(row+1,col)]=fa[idx];
        }
        else{
            if(findfa(idx)==findfa(get(row,col+1))){
                cout<<i;
                return 0;
            }
            else fa[get(row,col+1)]=fa[idx];
        }
    }
    cout<<"draw";
    return 0;
}