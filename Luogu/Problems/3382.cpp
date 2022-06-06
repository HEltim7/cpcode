#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

#define endl '\n'
using LL=long long;
const double eps=1e-6;
int n;
double l,r;
double para[20];

inline double cal(double x){
    double res=0;
    for(int i=0;i<=n;i++) res+=pow(x,i)*para[i];
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>l>>r;
    for(int i=n;i>=0;i--) cin>>para[i];
    
    while(l<r-eps){
        double lmid=l+(r-l)/2;
        double rmid=lmid+(r-lmid)/2;
        if(cal(lmid)>cal(rmid)) r=rmid;
        else l=lmid;
    }
    cout<<fixed<<setprecision(7)<<l<<endl;
    return 0;
}