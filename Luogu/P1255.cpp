#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;

string addition(string a,string b){
    if(a.length()<b.length()) swap(a,b);
    reverse(a.begin(),a.end()),reverse(b.begin(),b.end());
    while(a.length()!=b.length()) b+='0';
    int add=0,sum=0;
    string res;
    for(int i=0,j=0;i<a.length();i++,j++){
        sum=a[i]+b[i]-2*'0'+add;
        res+=(sum%10)+'0';
        add=sum>=10?1:0;
    }
    if(add) res+='1';
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    int n;
    cin>>n;
    string a="1",b="2",sum;
    if(n==0){
        cout<<0;
        return 0;
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    else if(n==2){
        cout<<2;
        return 0;
    }
    for(int i=3;i<=n;i++){
        sum=addition(a,b);
        a=b;
        b=sum;
    }
    cout<<sum;
    return 0;
}