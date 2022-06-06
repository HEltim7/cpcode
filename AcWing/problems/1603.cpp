#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n=0;
    cin>>n;
    int num[n];
    long long s1=0,s2=0;
    for(int i=0;i<n;i++) scanf("%d",&num[i]);
    sort(num,num+n);
    for(int i=0;i<n/2;i++) s1+=num[i];
    for(int i=0;i<(n+1)/2;i++) s2+=num[i+n/2];
    cout<<(n+1)/2-n/2<<' '<<s2-s1;
    return 0;
}