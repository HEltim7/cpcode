#include<iostream>
#include<queue>
using namespace std;
int aim,start,top,num[1000],passed[1000];

struct QElement
{
    int level;
    int step;
}tmp;
queue<QElement> q;//定义队列q，储存头节点数据的tmp

void bfs(){//广搜，向上下搜
    if(q.front().level==aim){cout<<q.front().step;return;}//结束
    if(q.empty()) {cout<<"-1";return;}//无
    tmp=q.front();
    int up=tmp.level+num[tmp.level];
    if (up<=top&&!passed[up])//上
    {
        tmp.level=up;
        tmp.step++;
        q.push(tmp);//加入
        passed[up]=1;
    }
    tmp=q.front();
    int dn=tmp.level-num[tmp.level];
    if (dn>=1&&!passed[dn])//下
    {
        tmp.level=dn;
        tmp.step++;
        q.push(tmp);//加入
        passed[dn]=1;
    }
    q.pop();//移除
    bfs();
}

int main(){
    cin>>top>>start>>aim;
    for(int i=1;i<=top;i++) cin>>num[i];
    tmp.level=start;
    tmp.step=0;
    q.push(tmp);
    passed[start]=1;
    bfs();
    return 0;
}