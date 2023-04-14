#include<bits/stdc++.h>
using namespace std;

int  main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=n;j+=2){
                cout<<"01";
            }
            cout<<endl;
        }
        else{
            for(int j=1;j<=n;j+=2){
                cout<<"10";
            }
            cout<<endl;
        }
    }
    return 0;
}