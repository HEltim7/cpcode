#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e7+10;
LL num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL n,idx;
    cin>>n;
    num[1]=num[2]=1;
    for(int i=3;;i++){
        num[i]=num[i-1]+num[i-2];
        if(num[i]>n) break;
        idx=i;
    }
    cout<<idx<<endl;
    for(int i=1;i<=idx;i++) cout<<num[i]<<' ';
    return 0;
}