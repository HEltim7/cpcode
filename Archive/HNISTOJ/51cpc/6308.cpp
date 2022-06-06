#include<iostream>
using namespace std;
const int N=1e6+10;
int nex[N];
int lenT,lenB;
// int sum;

void getnext(string in){
    nex[1]=1;
    for(int i=2,j=1;i<=lenB;i++){
        while(j>1&&in[i]!=in[j]) j=nex[j-1];
        if(in[i]==in[j]) j++;
        nex[i]=j;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    string text,base;
    getline(cin,text),getline(cin,base);
    lenT=text.length(),lenB=base.length();
    text=' '+text,base=' '+base;
    getnext(base);
    ////////////////////////////////////
    for(int i=1,j=1;i<=lenT;i++){
        while(j>1&&text[i]!=base[j]) j=nex[j-1];
        if(text[i]==base[j]) j++;
        if(j>lenB){
            // sum++;
            j=nex[j-1];
            cout<<i-lenB+1<<'\n';
        }
    }
    for(int i=1;i<=lenB;i++) cout<<nex[i]-1<<' ';
    return 0;
}