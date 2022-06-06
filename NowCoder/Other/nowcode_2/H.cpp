#include<iostream>
using namespace std;

int main(){
    long in;
    while(cin>>in&&in>0){
        int day=0;
        while(in>1){
            if(in%2==0){
                in/=2;
                day++;
            }
            else{
                in--;
                day++;
            }
        }
        cout<<day<<endl;
    }
    return 0;
}