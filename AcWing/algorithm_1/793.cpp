#include<iostream>
#include<algorithm>
using namespace std;

const int N=1e5+10;
int c[N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    string a;
    int b,i,t=0;
    cin>>a>>b;
    reverse(a.begin(),a.end());
    for(i=0;i<a.length();i++){
        c[i]=((a[i]-'0')*b+t)%10;
        t=((a[i]-'0')*b+t)/10;
    }
    while(t){
        c[i++]=t%10;
        t/=10;
    }
    while(c[i-1]==0&&i>1) i--;
    while(i--) cout<<c[i];
    return 0;
}