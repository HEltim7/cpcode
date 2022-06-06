#include<iostream>
using namespace std;
typedef long long ll;
int n;
int stack[20];

ll fn(int in){
    ll sum=0;
    int a=0,b=in-1;
    while(b>=0){
        sum+=(stack[a]*stack[b]);
        a++,b--;
    }
    return sum;
}

int main()
{
    cin>>n;
    stack[0]=1;
    stack[1]=1;
    for(int i=2;i<=n;i++) stack[i]=fn(i);
    cout<<stack[n];
    return 0;
}