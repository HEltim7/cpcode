#include<iostream>
using namespace std;
const int N=1e5+10;
int head[N],elem[N],nexe[N],mark[N];
int n,idx,qh,qt=-1;
bool flag;
struct que
{
    int num;
    int step;
} q[N];

void add(int a,int b){
    elem[idx]=b;
    nexe[idx]=head[a];
    head[a]=idx++;
}

bool empty(){
    if(qh>qt) return 1;
    return 0;
}

void push(que in) {q[++qt]=in;}

void bfs(){
    if(empty()) return;
    que tmp=q[qh];
    mark[tmp.num]=1;
    for(int i=head[tmp.num];i!=-1;i=nexe[i]){
        int j=elem[i];
        if(j==n){
            cout<<tmp.step;
            qh=qt+1;
            flag=1;
            return;
        }
        if(!mark[j]){
            mark[j]=1;
            tmp.num=j;
            tmp.step=tmp.step+1;
            push(tmp);
            tmp=q[qh];
        }
    }
    qh++;
    bfs();
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    fill(head,head+N,-1);
    int m,a,b;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        add(a,b);
    }
    que tmp;
    tmp.num=1,tmp.step=1;
    push(tmp);
    bfs();
    if(!flag) cout<<-1;
    return 0;
}