#include<iostream>
using namespace std;

int main(){
    string a,b,ans;
    cin>>a>>b;
    int ta=a.length()-1;
    int tb=b.length()-1;
    if(ta<tb){
        swap(a,b);
        swap(ta,tb);
    }
    while(ta!=tb){
        b='0'+b;
        tb++;
    }
    int add=0;
    while(ta>=0&&tb>=0){
        int sum=a[ta]+b[tb]-'0'*2+add;
        ans+=(sum%10)+'0';
        if(sum>=10) add=1;
        else add=0;
        ta--,tb--;
    }
    if(add) ans+='1';
    for(int i=ans.length()-1;i>=0;i--) cout<<ans[i];
    return 0;
}