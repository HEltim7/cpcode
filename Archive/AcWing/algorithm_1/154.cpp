#include<iostream>
using namespace std;
const int N=1e6+10;
int a[N],q[N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);//IO optimize
    int n,size;
    cin>>n>>size;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int hh=0,tt=-1;
    for(int i=0;i<=n;i++){
        //判断对头是否已经滑出窗口
        if(hh<=tt/*队列不为空*/&&i-size>=q[hh]/*队头出窗*/) hh++;
        while(hh<=tt&&a[q[tt]]>=a[i]/*砍掉队尾比a[i]大的*/) tt--;
        q[++tt]=i;
        if(i>=size/*前size-1个无输出*/) cout<<a[q[hh]]<<' ';
    }
    cout<<endl;
    hh=0,tt=-1;
    for(int i=0;i<=n;i++){
        //判断对头是否已经滑出窗口
        if(hh<=tt/*队列不为空*/&&i-size>=q[hh]/*队头出窗*/) hh++;
        while(hh<=tt&&a[q[tt]]<=a[i]/*砍掉队尾比a[i]小的*/) tt--;
        q[++tt]=i;
        if(i>=size/*前size-1个无输出*/) cout<<a[q[hh]]<<' ';
    }
    return 0;
}