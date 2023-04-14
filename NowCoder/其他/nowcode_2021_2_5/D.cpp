#include<iostream>
using namespace std;

int fn(int in){
    int sum=0;
    while(in>0){
        sum+=in%10;
        in/=10;
    }
    return sum;
}

int main(){
    int year,ans=0;
    cin>>year;
    ans=year+1;
    int sum=0;
    while(year>0){
        sum+=year%10;
        year/=10;
    }
    int summ=0;
    summ=fn(ans);
    while(summ!=sum){
        ans++;
        summ=fn(ans);
    }
    cout<<ans;
    return 0;
}