#include<iostream>
using namespace std;

int sameh,ans[110];
struct h_data
{
    int h;
    int left;//左边比当前小的
    int right;//右边比当前大的
} t[110];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>t[i].h;
        if(t[i].h==t[i-1].h) sameh++;//同高，直接加至结果
        i--,n--;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(t[i].h<t[j].h) t[j].left++;
            else t[i].right++;//前面已经去重，直接else
        }
    }
    
}