#include<iostream>
using namespace std;
const int N=100010;
long nums[N];

long long fn(int step){
    long long ans=0;
    while (step>=1){
        ans+=step;
        step--;
    }
    return ans;
}

int main(){
    int siz,step=1;
    long long res=0;
    cin>>siz;
    for(int i=1;i<=siz;i++) scanf("%d",&nums[i]);
    for(int i=1;i<=siz;i++){
        if(nums[i+1]>=nums[i]&&(i+1)<=siz) step++;
        else{
            res+=fn(step);
            step=1;
        }
    }
    cout<<res;
    return 0;
}