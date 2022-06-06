#include<vector>
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

#define endl '\n'
using LL=long long;
const int INF=0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int max1=-1,max2=-1;
    double ans=-1;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        if(in>max1){
            max2=max1;
            max1=in;
        }
        else if(in!=max1&&in>max2){
            max2=in;
        }
    }
    if(max2==-1) cout<<"-1";
    else cout<<fixed<<setprecision(1)<<(max1+max2)*1./2;
    return 0;
}