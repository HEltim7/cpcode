#include<iostream>
using namespace std;
string base,aim;
int sum;

void str(){
    for(int i=0;i<aim.length()-base.length()+1;i++){
        for(int j=0;j<base.length();j++){
            if(aim[i+j]!=base[j]) break;
            if(j==base.length()-1){
                cout<<i<<' ';
                sum++;
            }
        }
    }
    cout<<endl<<sum<<endl;
}