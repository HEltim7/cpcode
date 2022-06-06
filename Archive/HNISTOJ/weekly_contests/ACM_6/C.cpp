#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll data[30];


int main(){
    cin>>data[0]>>data[1]>>data[2];
    for(int i=3;i<=20;i++){
        data[i]=data[i-1]+data[i-2]*2+data[i-3];
    }
    for(int i=0;i<=20;i++){
        cout<<data[i]<<" ";
    }
    return 0;
}