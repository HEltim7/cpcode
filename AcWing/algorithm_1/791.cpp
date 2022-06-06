#include<iostream>
#include<algorithm>
using namespace std;

string mkstr(int num){
    string str;
    do str+=num%10+'0'; while(num/=10);
    reverse(str.begin(),str.end());
    return str;
}

string addition(string a,string b){
    if(a.length()<b.length()) swap(a,b);
    reverse(a.begin(),a.end()),reverse(b.begin(),b.end());
    while(a.length()!=b.length()) b+='0';
    int add=0,sum=0;
    for(int i=0;i<a.length();i++){
        sum=a[i]+b[i]-'0'*2+add;
        if(sum>9) add=1; else add=0;
        a[i]=sum%10+'0';
    }
    if(add) a+='1';
    reverse(a.begin(),a.end());
    return a;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    string a,b;
    cin>>a>>b;
    cout<<addition(a,b);
    return 0;
}