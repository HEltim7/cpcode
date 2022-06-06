#include<bits/stdc++.h>
using namespace std;
string EasterEgg="(= • ω • =)";
#define MAX 9223372036854775807
typedef unsigned long long ull;
int level,allDisk,findLevel=4,bestWay[101][1000];
ull step,minStep[101][1000];
string initialPegsStatus;

ull GetStep(int former,int latter){//计算步数
    if(findLevel==4){return 2*minStep[findLevel][former]+(ull)pow(2,latter)-1;}
    else {return 2*minStep[findLevel][former]+minStep[findLevel-1][latter];}
}

void FindBestWay(){//搜索最优解
    if(findLevel>level){return;}//结束
    for(int i=findLevel;i<=allDisk;i++){//从第一个非基准情况开始递推寻找接下来每层最优解
        ull tmp=MAX;
        int tmpdisk=0;
        for(int j=1;j<i;j++){//遍历寻找1~i-1，移动上j个盘，disk-j盘调用上阶hanoi的解
            if(tmp>GetStep(j,i-j)){//更优解
                tmpdisk=j;
                tmp=GetStep(j,i-j);
            }
        }
        minStep[findLevel][i]=tmp;//记录最优解
        bestWay[findLevel][i]=tmpdisk;
    }
    findLevel++;
    FindBestWay();
}

string pegDisable(string pegs,int i){//抹去i柱
    pegs[i]='0';
    return pegs;
}

string pegEnable(string pegs,int i){//激活i柱
    pegs[i]='1';
    return pegs;
}

void hanoi3(long in,int source,int tmp,int aim){
    if(in==1){
        cout<<"step["<<++step<<"]:"<<source<<"-->"<<aim<<endl;
        return;
    }
    hanoi3(in-1,source,aim,tmp);
    hanoi3(1,source,tmp,aim);
    hanoi3(in-1,tmp,source,aim);
    return;
}

void hanoiN(int disk,string pegs,int nowLevel,int source,int aim){//disk储存盘数,pegs储存柱状态,nowlevel储存柱等级,source源柱,aim目标柱
    //基准情况↓
    if(disk<=nowLevel-2&&nowLevel>3){//调用上阶解
        hanoiN(disk,pegs,nowLevel-1,source,aim);
        return;
    }
    //寻找可用辅助柱
    int pegsMark[level-1]={0},j=0;
    for(int i=1;i<=level&&j<nowLevel;i++){
        if(pegs[i]=='1'&&i!=source&&i!=aim){
            pegsMark[++j]=i;
        }
    }
    //该阶独有的最优解
    if(disk==nowLevel-1&&nowLevel>3){
        for(int i=1;i<=nowLevel-2;i++){//输出本级最优解，左优先
            cout<<"Step["<<++step<<"]:"<<source<<"-->"<<pegsMark[i]<<endl;//移动上nowlevel-2个盘
        }
        cout<<"Step["<<++step<<"]:"<<source<<"-->"<<aim<<endl;//移动底盘到aim
        for(int i=nowLevel-2;i>=1;i--){
            cout<<"Step["<<++step<<"]:"<<pegsMark[i]<<"-->"<<aim<<endl;//移动上nowlevel-2个盘
        }
        return;
    }
    //三阶塔,结束外递归
    if(nowLevel==3){
        hanoi3(disk,source,pegsMark[1],aim);
        return;
    }
    //非基准情况↓
    hanoiN(bestWay[nowLevel][disk],pegs,nowLevel,source,pegsMark[1]);//移动上层至tmp柱,左优先
    hanoiN(disk-bestWay[nowLevel][disk],pegDisable(pegs,pegsMark[1]),nowLevel-1,source,aim);//移动下层
    hanoiN(bestWay[nowLevel][disk],pegEnable(pegs,pegsMark[1]),nowLevel,pegsMark[1],aim);//移动上层至tmp柱,左优先
    return;
}

string initialization(){//初始化
    minStep[4][1]=1;
    minStep[4][2]=3;
    minStep[4][3]=5;
    minStep[4][4]=9;
    string tmp;
    for(int i=1;i<=level;i++){tmp+='1';}//激活level个柱
    tmp='0'+tmp;
    for(int i=5;i<=level;i++){//初始化各阶基准解
        for(int j=1;j<=i-2;j++){
            minStep[i][j]=minStep[i-1][j];
        }
        minStep[i][i-1]=(i-2)*2+1;
    }
    return tmp;
}

int main(){
    cout<<"[INFO]please enter the pegs amount of hanoi:"<<endl;
    if(cin>>level&&level<3){cout<<"[ERROR]ILLEDAL NUMBER!";return 0;}
    cout<<"[INFO]please enter the disk amount:"<<endl;
    cin>>allDisk;
    initialPegsStatus=initialization();
    FindBestWay();
    hanoiN(allDisk,initialPegsStatus,level,1,level);
    cout<<"[INFO]TotalSteps:"<<step<<endl;
    //for(;;)cout<<EasterEgg<<endl;
    return 0;
}