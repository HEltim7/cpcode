#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=210;
LL a[N],b[N],c[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=n;i>=0;i--) cin>>a[i];
    for(int i=n+m;i>=0;i--) cin>>c[i];
    b[0]=c[0]/a[0];
    for(int i=1;i<=m;i++){
        LL sum=0;
        for(int j=1;j<=i;j++) sum+=a[j]*b[i-j];
        b[i]=(c[i]-sum)/a[0];
    }
    for(int i=m;i>=0;i--) cout<<b[i]<<' ';
    return 0;
}