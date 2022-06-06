//3375
#include<bits/stdc++.h>
using namespace std;
string s1,s2;//s1模板串 s2文本串
long pmt[1000];
long sum,loc[1000],len;
void getPmt(){//自身对比，算后缀和前缀相同的位数-1
    for(int i=1,j=0;i<=s1.length();i++){
        if (s1[i]==s1[j])
        {
            pmt[i]=j++;
        }
        else{
            if(j&&(j=pmt[j-1])){
                j++;
                i--;
            }
        }
    }
}
void kmp(){
    for(int i=0,j=0;i<s2.length();i++){
        if(s2[i]==s1[j]){
            j++;
        }
        else{
            j=j?pmt[j-1]:0;
        }
        if(j==len){
            loc[++sum]=i-len+1;
            j=(pmt[len-1]?pmt[len-1]+1:0);
        }
    }
}
int main(){
    getline(cin,s1);
    getline(cin,s2);
    len=s1.length();
    getPmt();
    kmp();
    for(int i=1;i<=sum;i++)cout<<loc[i]<<' ';
    return 0;
}