#include<iostream>
using namespace std;
typedef unsigned long long ull;
int main(){
    ull a,in,sum=0;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>in;
        sum+=in;
    }
    cout<<sum;
    return 0;
}