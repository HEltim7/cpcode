#include<iostream>
using namespace std;
long step;


void hanoi(long in,char source,char tmp,char aim){
    if(in==1){
        step++;
        cout<<"step["<<step<<"]:"<<source<<"-->"<<aim<<endl;
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
    hanoi(n,'a','b','c');
    cout<<"TotalStep:"<<step;
    return 0;
}