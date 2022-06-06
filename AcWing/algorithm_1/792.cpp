#include<iostream>
#include<algorithm>
using  namespace std;
string a,b;

bool bigger(string a,string b){
    if(a.length()>b.length()) return 1;
    else if(a.length()<b.length()) return 0;
    for(int i=0;i<a.length();i++) if(a[i]>b[i]) return 1; else if(a[i]<b[i]) return 0;
    return 1;
}

string fn(string a,string b){
    bool neg=!bigger(a,b);
    if(neg) swap(a,b);
    reverse(a.begin(),a.end()),reverse(b.begin(),b.end());
    while(b.length()<a.length()) b+='0';
    int sub=0,sum=0;
    for(int i=0;i<a.length();i++){
        sum=a[i]-b[i]-sub;
        if(sum<0) sub=1,sum+=10; else sub=0;
        a[i]=sum+'0';
    }
    while(a[a.length()-1]=='0'&&a.length()>1) a.pop_back();
    if(neg) a+='-';
    reverse(a.begin(),a.end());
    return a;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>a>>b;
    cout<<fn(a,b);
    return 0;
}