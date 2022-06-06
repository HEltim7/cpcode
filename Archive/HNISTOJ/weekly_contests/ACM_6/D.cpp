#include<iostream>
#include<algorithm>
using namespace std;
#define isok(i) tower[i][top[i]]%2==tower[pos][top[pos]]%2
typedef long long ll;
typedef unsigned long long ull;
int n,tower[4][100],top[4];
char name[4]{'0','A','B','C'};
ull step;

void mov(int pos,int aim){
    top[aim]++;
    tower[aim][top[aim]]=tower[pos][top[pos]];
    tower[pos][top[pos]]=0;
    top[pos]--;
    return;
}

void hanoi(int pos,int aim){
    if(top[pos]==1){//只有一个碟
        cout<<tower[pos][top[pos]]<<' '<<name[pos]<<' '<<name[aim]<<endl;
        mov(pos,aim);
        step++;
        return;
    }
    //////////////////////
    if(top[aim]==0&&top[3]==0){
        top[pos]=2;
        for(int i=2;i<=n;i++){
            mov(pos,3);
            top[pos]+=2;
        }
        top[pos]=1;
        hanoi(pos,3);

        mov(pos,aim);
        hanoi(pos,aim);

        top[3]=2;
        for(int i=2;i<=n;i++){
            mov(3,aim);
            top[3]+=2;
        }
        top[3]=1;
        hanoi(3,aim);
        return;
    }

    /*
    这就是个普通汉诺塔！！！！
    */
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        tower[1][n-i+1]=i;
    }
    top[1]=n;
    hanoi(1,2);
    return 0;
}