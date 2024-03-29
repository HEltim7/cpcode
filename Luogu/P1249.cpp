#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
string sum="1";
int num[10000];

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

string make_string(int num){
    string res;
    while(num){
        res+=num%10+'0';
        num/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    int n,now=1,nowi=0;
    cin>>n;
    while(n-++now>=0){
        num[++nowi]=now;
        n-=now;
    }
    for(int i=nowi;i>=1&&n--;i--){
        num[i]++;
        if(i==1) i=nowi+1;
    }
    for(int i=1;i<=nowi;i++){
        cout<<num[i]<<' ';
        sum=mul(sum,make_string(num[i]));
    }
    cout<<endl<<sum;
    return 0;
}