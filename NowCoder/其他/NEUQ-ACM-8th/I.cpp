#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int q;
    cin>>q;
    for(int z=1;z<=q;z++){
        int aim=0;
        bool flag=0;
        cin>>aim;
        for(int k=2;k<=15;k++){
            long day=pow(2,k)-1;
            if(aim%day==0){
                cout<<"YE5"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0) cout<<"N0"<<endl;
    }
    return 0;
}