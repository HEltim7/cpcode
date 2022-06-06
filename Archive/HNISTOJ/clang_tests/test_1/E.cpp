#include<bits/stdc++.h>
using namespace std;
double fn(int x,int n,double ans){
    if(n==1)
        return sqrt(x);
    else
    {
        ans=sqrt(x+fn(x,n-1,ans));
    }
    return ans;
}

int main(){
    int x,n;
    cin>>x>>n;
    cout<<fixed<<setprecision(2)<<fn(x,n,0);
    return 0;
}