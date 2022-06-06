#include<iostream>
using namespace std;
unsigned long long fn(unsigned long long in){
    unsigned long long op=0;
    while(in){
        op+=in%10;
        in/=10;
    }
    if (op<10)
        return op;
    else
        return fn(op);
}
int main(){
    unsigned long long in;
    cin>>in;
    while(in!=0){
        cout<<fn(in)<<endl;
        cin>>in;
    }
    return 0;
}