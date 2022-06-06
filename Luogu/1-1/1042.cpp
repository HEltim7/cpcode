#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(0);
    string str,tmp;
    int a=0,b=0,i;
    while(getline(cin,tmp)){
        str+=tmp;
    }
    for(i=0;str[i]!='E';i++){
        if(str[i]=='W') a++;
        else b++;
        if((a>=11||b>=11)&&abs(a-b)>=2){
            cout<<a<<':'<<b<<endl;
            a=0,b=0;
        }
    }
    cout<<a<<':'<<b<<endl;
    a=0,b=0;
    cout<<endl;
    for(i=0;str[i]!='E';i++){
        if(str[i]=='W') a++;
        else b++;
        if((a>=21||b>=21)&&abs(a-b)>=2){
            cout<<a<<':'<<b<<endl;
            a=0,b=0;
        }
    }
    cout<<a<<':'<<b<<endl;
    return 0;
}