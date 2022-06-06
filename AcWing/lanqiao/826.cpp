#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+10;
int elem[N],nexe[N],idx=1;

void head(int in){
    elem[idx]=in;
    nexe[idx]=nexe[0];
    nexe[0]=idx++;
}

void insert(int loc,int in){
    elem[idx]=in;
    nexe[idx]=nexe[loc];
    nexe[loc]=idx++;
}

void del(int loc){
    nexe[loc]=nexe[nexe[loc]];
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(nexe,-1,sizeof nexe);
    int n,loc,in;
    char op;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>op;
        if(op=='H'){
            cin>>in;
            head(in);
        }
        else if(op=='I'){
            cin>>loc>>in;
            insert(loc,in);
        }
        else{
            cin>>loc;
            del(loc);
        }
    }
    for(idx=nexe[0];idx!=-1;idx=nexe[idx]) cout<<elem[idx]<<' ';
    return 0;
}