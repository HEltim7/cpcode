#include<iostream>
using namespace std;
const int N=1e6+10;
string base,str;
int nexe[N];

void getnext(){
    for(int i=1,j=0;i<base.length();i++){
        while(j&&base[i]!=base[j]) j=nexe[j];
        if(base[i]==base[j]) j++;
        nexe[i+1]=base[i+1]==base[j]?nexe[j]:j;
    }
}

int main(){
    cout<<"模版串：";
    getline(cin,base);
    cout<<"匹配串：";
    getline(cin,str);
    getnext();
    for(int i=0,j=0;i<=str.length();i++){
        if(j==base.length()){
            cout<<i-base.length()<<' ';
            j=nexe[j];
        }
        while(j&&str[i]!=base[j]) j=nexe[j];
        if(str[i]==base[j]) j++;
    }
    return 0;
}