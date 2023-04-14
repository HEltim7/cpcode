#include<iostream>
using namespace std;

#define endl '\n'

void exgcd(int a,int b,int &s,int &t){
    if(b==0){
        s=1,t=0;
        return ;
    }
    exgcd(b,a%b,t,s);
    t=t-a/b*s;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c;
    cin>>c;
    while(c--){
        int a,b,s,t;
        cin>>a>>b;
        exgcd(a,b,s,t);
        cout<<s<<' '<<t<<endl;
    }
    return 0;
}