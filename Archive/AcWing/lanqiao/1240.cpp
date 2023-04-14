#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int n;
int tree[N];
ll sum[100];
struct qnode{
    int idx;
    int deep;
} tmp;
queue <qnode> que;
int maxx;

void bfs(){
    if(que.empty()) return;
    tmp=que.front();
    sum[tmp.deep]+=tree[tmp.idx];
    if(tmp.idx*2<=n){
        tmp.deep++;
        tmp.idx=tmp.idx*2;
        que.push(tmp);
        if(++tmp.idx<=n) que.push(tmp);
    }
    que.pop();
    bfs();
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>tree[i];
    tmp.idx=1;
    tmp.deep=1;
    que.push(tmp);
    bfs();
    maxx=log2(n)+1;
    for(int i=log2(n)+1;i>=1;i--) if(sum[i]>=sum[maxx]) maxx=i;
    cout<<maxx;
    return 0;
}