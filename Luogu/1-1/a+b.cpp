#include<iostream>
#include<algorithm>
using namespace std;

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
    string a,b;
    cin>>a>>b;
    cout<<addition(a,b);
    return 0;
}

// string reverse(string str){
//     string res;
//     for(int i=str.length()-1;i>=0;i--) res+=str[i];
//     return res;
// }