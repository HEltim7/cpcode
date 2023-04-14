#include<iostream>
using namespace std;
int main(){
    string in;
    cin>>in;
    int last=in[in.length()-1]-'0';
    if(last%2==1) cout<<1;
    else cout<<2;
}