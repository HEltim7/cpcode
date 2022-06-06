#include<iostream>
using namespace std;
long step;
int data[4][100],top[4];
char name[4]={'0','A','B','C'};
void hanoi(long in,int source,int tmp,int aim){
    if(in==1){
        cout<<data[source][top[source]]<<' '<<name[source]<<' '<<name[aim]<<endl;
        top[aim]++;
        data[aim][top[aim]]=data[source][top[source]];
        top[source]--;
        return;
    }
    hanoi(in-1,source,aim,tmp);
    hanoi(1,source,tmp,aim);
    hanoi(in-1,tmp,source,aim);
    return;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        data[1][n-i+1]=i;
        top[1]=n;
    }
    hanoi(n,1,3,2);
    return 0;
}