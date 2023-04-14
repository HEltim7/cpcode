//打表正解（雾，排列组合gcd
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,in,tmp;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>in;
        if(in==1){
            cout<<"0/1"<<endl;
            continue;
        }
        //tmp=__gcd(in-1,in);
        cout<<'1'<<'/'<<in<<endl;
    }
    return 0;
}