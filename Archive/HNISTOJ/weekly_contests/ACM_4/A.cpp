#include<iostream>
using namespace std;
int num[8]={0,3,5,6,9,10,12,15};
int main()
{
    long long in;
    while((scanf("%lld",&in))!=EOF){
        long long t=in/7;
        cout<<t*15+num[in%7]<<endl;
    }
    return 0;
}