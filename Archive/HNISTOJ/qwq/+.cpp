#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
///还是手动reverse比较好（
string add(string a,string b){
    if(a.length()<b.length()){
        string c=b;
        b=a;
        a=c;
    }
    ull head=b.length();
    while (a.length()!=b.length())
        b='0'+b;
    ull tail=b.length()-1;
    head=tail-head+1;
    for(ull i=tail;i>head;i--){
       if(a[i]+b[i]-'0'*2>9){
           a[i]+=b[i]-'0'-10;
           a[i-1]+=1;
       }
       else{
           a[i]+=b[i]-'0';
       }
    }
    //////////////////////////////
    if(a[0]+b[0]-'0'*2>9){
        a[0]+=b[0]-'0'-10;
        a='1'+a;
    }
    else{
        if(a[head]+b[head]-'0'*2>9){
           a[head]+=b[head]-'0'-10;
           a[head-1]+=1;
       }
       else{
           a[head]+=b[head]-'0';
       }
    }
    return a;
}

string addition(char s1[1000],char s2[1000]){
    reverse(s1,s1+strlen(s1));
    reverse(s2,s2+strlen(s2));
    string a=s1,b=s2;
    char c[1000];
    if(a.length()<b.length()){
        string c=b;
        b=a;
        a=c;
    }
    int len=b.length();
    for(int i=0;i<len;i++){
        if(i<len-1&&a[i]+b[i]-'0'*2>9){
            a[i]+=b[i]-'0'-10;
            a[i+1]++;
        }
        else if(a[i]+b[i]-'0'*2>9){
            a[i]+=b[i]-'0'-10;
            a[i+1]='1';
            c[i+1]=a[i+1];
        }
        else a[i]+=b[i]-'0';
        c[i]=a[i];
    }
    reverse(c,c+strlen(c));
    return c;
}

string substraction(char s1[1000],char s2[1000]){
    bool neg=0;
    string a,b;
    if(strlen(s1)<strlen(s2)||strlen(s1)==strlen(s2)&&s1<s2) neg=1;
    reverse(s1,s1+strlen(s1));
    reverse(s2,s2+strlen(s2));
    if(neg) a=s2,b=s1;
    else a=s1,b=s2;
    while(a.length()!=b.length()) b=b+'0';
    int len=a.length(),next=0,i;
    char c[1000];
    for(i=0;i<len;i++){
        if(a[i]+next>=b[i]){
            a[i]=a[i]-b[i]+'0'+next;
            next=0;
        }
        else{
            a[i]=a[i]-b[i]+'0'+next+10;
            next=-1;
        }
        c[i]=a[i];
    }
    if(neg) c[i]='-';
    reverse(c,c+strlen(c));
    return c;
}


string multiplication(){
    return "";
}


int main(){
    char a[1000]="823479812739407219300";
    char b[1000]="93259234895349050934";
    //cout<<addition(a,b);
    cout<<substraction(a,b);
    return 0;
}