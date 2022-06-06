#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a=1;
    int *p1=&a;
    int *p2=p1;
    int **p3=&p1;
    int ***p4=&p3;
    //加个断点

    int data[100][100]={0};
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            data[i][j]=i+j;
        }
    }
    int (*q1)[100];
    int *q2;
    q1=&data[0];
    q2=&data[0][0];
    

    return 0;
}