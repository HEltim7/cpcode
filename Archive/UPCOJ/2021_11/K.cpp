#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a;
    if(a==6){
        cin>>b;
        if(b==6){
            cin>>c;
            if(c==6){
                cout<<1000;
                return 0;
            }
            cout<<100;
            return 0;
        }
        cout<<10;
        return 0;
    }
    cout<<0;
    return 0;
}