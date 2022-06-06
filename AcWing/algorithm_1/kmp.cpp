#include<iostream>
using namespace std;
const int N=1e4+10;
int nex[N];
string aim,base;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;
    //数组从1开始
    getline(cin,aim);
    m=aim.length();
    aim=' '+aim;
    getline(cin,base);
    n=base.length();
    base=' '+base;

    ///////////////get next//////////////

    nex[1]=1;//nex[匹配成功数]=移动坐标
    //nex[x]表示到x为止都成功时给j赋的值,nex[n]匹配完成时给j赋的值
    for(int i=2,j=1;i<=n;i++){
        //base[1]==base[1]
        while(j>1/*防止j=1死循环*/&&base[i]!=base[j]) j=nex[j-1];//匹配失败
        if(base[i]==base[j]) j++;//匹配成功
        nex[i]=j;//到i为止匹配成功
    }

    ////////////////kmp//////////////////
    
    for(int i=1,j=1;i<=m;i++){
        while(j>1&&aim[i]!=base[j]) j=nex[j-1];
        if(aim[i]==base[j]) j++;
        if(j>n){
            cout<<i-n+1<<' ';
            j=nex[n];
        }
    }
    return 0;
}