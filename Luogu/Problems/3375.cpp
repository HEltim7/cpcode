#include<bits/stdc++.h>
using namespace std;
string model,text;//model模板串 text文本串
long pmt[1000],nextval[1000];//pmt表示前后缀有几位相同，nextval表示若该位匹配失败跳至哪位
long sum,loc[1000],len;
//!!!!pmt数组可以和nextval合并
void getPmt(){//自身对比，算后缀和前缀相同的位数
    for(int i=1,j=0;i<model.length();i++){
        if (model[i]==model[j])
            pmt[i]=++j;
        else if(j){
            j=pmt[j-1];
            i--;
        }
    }
}
void getnext(){//除断点处不同，其他相同
    for(int i=1,j=0;i<model.length();i++){
        if(model[i]==model[j]){
            j++;
        }
        else if(j){
            nextval[i]=j;
            j=0;
        }
    }
}

void kmp(){
    for(int i=0,j=0;i<text.length();i++){
        if(text[i]==model[j]){
            j++;
        }
        else{
            j=nextval[j];
        }
        if(j==len){
            loc[++sum]=i-len+2;
            j=(pmt[len-1]?pmt[len-1]:0);
        }
    }
}
int main(){
    getline(cin,text);
    getline(cin,model);
    len=model.length();
    getnext();
    getPmt();
    kmp();
    for(int i=1;i<=sum;i++)cout<<loc[i]<<endl;
    for(int i=0;i<len;i++)cout<<pmt[i]<<' ';
    return 0;
}