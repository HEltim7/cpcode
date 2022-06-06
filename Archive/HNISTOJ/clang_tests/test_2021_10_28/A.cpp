#include<iostream>
using namespace std;

#define endl '\n'
const int N=110;
int ans[N],in[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++) cin>>in[j];
        for(int j=1;j<=i;j++) in[j]+=max(ans[j-1],ans[j]);
        for(int j=1;j<=i;j++) ans[j]=in[j];
    }
    int res=0;
    for(int i=1;i<=n;i++) res=max(res,ans[i]);
    cout<<res;
}