#include<iostream>
using namespace std;

void quick_sort(int q[],int l,int r){
    if(l>=r) return;
    int x=q[r],i=l-1,j=r+1;
    while(i<j){
        do i++; while(q[i]<x);
        do j--; while(q[j]>x);
        if(i<j) swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}

int main(){
    // int n,num[20];
    // cin>>n;
    // for(int i=1;i<=n;i++) cin>>num[i];
    // quick_sort(num,1,n);
    // for(int i=1;i<=n;i++) cout<<num[i]<<' ';

}