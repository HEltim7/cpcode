#include<bits/stdc++.h>
int main(){
    long long n;
    int count=0;
    while(scanf("%ld",&n)!=EOF){
        for(int i=2;i<=sqrt(n);i++){
            while(n%i==0){
                count++;
                n/=i;
            }
        }
        if(n!=1) count++;//此时n必为大于sqrt(n)的质数
        printf("%d\n",count);
        count=0;
    }
    return 0;
}