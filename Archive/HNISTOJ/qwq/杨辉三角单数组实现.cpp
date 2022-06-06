#include<iostream>
using namespace std;
const int N=110;
int num[N];

int main(){
    num[1]=1;
    for(int i=1;i<=10;i++){
        int tail=i;
        while(tail) num[tail--]=num[tail]+num[tail-1];
        for(int j=1;j<=i;j++) cout<<num[j]<<' ';
        cout<<endl;
    }
    return 0;
}