#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const long N=100010;
long city[N],len[N],k,node[N];

bool cmp(long a,long b){
    return a>b;
}

int main(){
    long n;
    cin>>n>>k;
    for(int i=0;i<n;i++) scanf("%d",&city[i]);
    sort(city,city+n);
    for(int i=1;i<n;i++){
        len[i]=city[i]-city[i-1];
    }
    sort(len+1,len+n,cmp);
    while(k>=1){
        for(int i=1;i<n;i++){//寻找最大分割
            
        }
        k--;
    }
}

