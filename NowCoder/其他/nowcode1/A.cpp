#include<iostream>
#include<cstring>
using namespace std;
int fn(){
    int sum=0;
    bool alpha[256];
    string str;
    memset(alpha,0,sizeof(alpha));
    getline(cin,str);
    for(int i=0;i<str.length();i++) alpha[str[i]]=true;
    for(int i=1;i<256;i++) if(alpha[i]) sum++;
    return sum;
}
int main(){
    printf("%d",fn());
    return 0;
}