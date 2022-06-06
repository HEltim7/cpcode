#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=200000;
LL num[N],dif[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    LL maxx=0,res=0;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>num[i];
        maxx=max(maxx,num[i]);
        if(i!=1) dif[i]=num[i]-num[i-1];
    }
    dif[1]=num[1]-num[n];
    for(int i=1;i<=n;i++) res+=abs(dif[i]);
    cout<<max(maxx,res/2);
    return 0;
}