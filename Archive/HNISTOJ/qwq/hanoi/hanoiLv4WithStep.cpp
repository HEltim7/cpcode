#include<iostream>
using namespace std;
void EasterEgg()
{cout<<"ヾ(≧▽≦*)o"<<endl;}
#include<cstdlib>
#include<cmath>
#define MAX 9223372036854775807
#define GETSTEP(former,latter) 2*minStep[former]+(ull)pow(2,latter)-1//计算步数
typedef unsigned long long ull;
int disk,bestWay[1000];
ull step,minStep[1000]={0,1,3,5};

void findBestWay(){
    for(int i=4;i<=disk;i++){//从第一个非基准情况开始递推寻找接下来每层最优解
        ull tmp=MAX;
        int tmpdisk=1;
        for(int j=1;j<i;j++){//遍历寻找1~i-1，移动上j个盘，disk-j盘调用上阶hanoi的解
            if(tmp>GETSTEP(j,i-j)){//更优解
                tmpdisk=j;
                tmp=GETSTEP(j,i-j);
            }
        }
        minStep[i]=tmp;//记录最优解
        bestWay[i]=tmpdisk;
    }
}

void hanoi3(long in,char source,char tmp,char aim){
    if(in==1){
        cout<<"step["<<++step<<"]:"<<source<<"-->"<<aim<<endl;
        return;
    }
    hanoi3(in-1,source,aim,tmp);
    hanoi3(1,source,tmp,aim);
    hanoi3(in-1,tmp,source,aim);
    return;
}

void hanoi4(int in,char source,char tmp1,char tmp2,char aim){
    //基准情况↓
    if(in==1||in==2){//in=1or2时调用上阶hanoi的解
        hanoi3(in,source,tmp1,aim);// 输出时自加
        return;
    }
    if(in==3){//in=3(in<hanoi阶数)时,4阶hanoi有与前不同的最优解,按就近优先
        cout<<"step["<<++step<<"]:"<<source<<"-->"<<tmp1<<endl;
        cout<<"step["<<++step<<"]:"<<source<<"-->"<<tmp2<<endl;
        cout<<"step["<<++step<<"]:"<<source<<"-->"<<aim<<endl;
        cout<<"step["<<++step<<"]:"<<tmp2<<"-->"<<aim<<endl;
        cout<<"step["<<++step<<"]:"<<tmp1<<"-->"<<aim<<endl;
        return;
    }
    //非基准情况↓
    hanoi4(bestWay[in],source,tmp2,aim,tmp1);//移动上层满足最优解的盘组到辅助柱
    hanoi3(in-bestWay[in],source,tmp2,aim);//下层调用上阶hanoi的解
    hanoi4(bestWay[in],tmp1,source,tmp2,aim);//移动第一次的盘组到目标柱
    return;
}

int main(){
    cin>>disk;
    if(disk>64){cout<<"[ERROR]The number is too big!";return 0;}//上限64
    findBestWay();//搜索最优解
    hanoi4(disk,'a','b','c','d');//执行盘移动
    cout<<"TotalSteps:"<<step<<endl;
    //EasterEgg();//完结撒花
    return 0;
}