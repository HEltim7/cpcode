#include<iostream>
#include<cmath>
using namespace std;

const long MAX=6889000;
int n;
long res[100]={0},ans=MAX;

void quick_sort(int q[],int l,int r){
    if(l>=r) return;
    int x=q[l],i=l-1,j=r+1;
    while (i<j)
    {
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}

int main(){
    cin>>n;
    int mountain[n+1];
    for(int i=1;i<=n;i++) scanf("%d",&mountain[i]);
    for(int i=0,j=17;i<=83&&j<=100;i++,j++){
        for(int k=1;k<=n;k++)
            if(mountain[k]<i||mountain[k]>j)
                res[i]+=min(pow(mountain[k]-i,2),pow(mountain[k]-j,2));
        ans=min(res[i],ans);
    }
    cout<<ans;
    return 0;
}