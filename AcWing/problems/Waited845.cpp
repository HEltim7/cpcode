//已归档，需要哈希基础
#include<iostream>
using namespace std;
const int N=1e6;
struct q_node
{
    string matrix;
    int step;
    int x;
} que[N];
int head,tail,finded;

void qpush(string matrix,int step,int x){
    que[tail++].matrix=matrix;
}

bool qempty(){
    if(head>=tail) return 0;
    return 1;
}

bool check(string in){
    if(in=="012345678x") return 1;
    return 0;
}

void bfs(){
    if(qempty()||finded) return;
    string tmp=que[head].matrix;
    int x=que[head].x;
    if(x+1<=9){
        
    }
}

int main(){
    string matrix="0123456789";
    char in;
    int x;
    for(int i=1;i<=9;i++){
        cin>>in;
        if(in=='x') x=i;
        matrix[i]=in;
    }
    qpush(matrix,0,x);
    while(!qempty()){
        
    }
}