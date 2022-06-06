#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    char in1[100]={0},in2[100]={0};
    cin>>in1;
    char *q=&in2[0];
    char *p=&in1[0];
    while (p-&in1[0]<strlen(in1))
        *(q++)=*(p++);
    cout<<in2;
    return 0;
}