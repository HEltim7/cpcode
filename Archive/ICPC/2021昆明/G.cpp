#include<vector>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=110;
double p[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    double ans=0;
    for(int i=1;i<=n;i++){
        double res=0;
        for(int j=1;j<=n;j++)
            if(i!=j) res+=p[j]/(p[i]+p[j]);
        ans+=p[i]*res;
    }
    cout<<fixed<<setprecision(12)<<ans;
    return 0;
}