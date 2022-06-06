#include<iostream>
#include<algorithm>
using namespace std;

string mul(string a,string b){
    if(a=="0"||b=="0") return "0";
    int tmp[a.length()+b.length()+10]={0};
    string res;
    reverse(a.begin(),a.end()),reverse(b.begin(),b.end());
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            int p=(a[i]-'0')*(b[j]-'0');
            int level=i+j;
            while(p){
                tmp[level]+=p%10;
                level++;
                p/=10;
            }
        }
    }
    for(int i=0;i<a.length()+b.length()+10;i++){
        int level=1,now=tmp[i]/10;
        while(now){
            tmp[i+level]+=now%10;
            now/=10;
            level++;
        }
        tmp[i]=tmp[i]%10;
    }
    for(int i=a.length()+b.length()+9;i>=0;){
        if(tmp[i]==0) i--;
        else{
            for(;i>=0;i--) res+=tmp[i]+'0';
            break;
        }
    }
    return res;
}

int main(){
    string a,b;
    cin>>a>>b;
    cout<<mul(a,b);
    return 0;
}