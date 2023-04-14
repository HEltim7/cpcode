#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=1e5+10;
const int INF=0x3f3f3f3f;
int LIS[N];
int num[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];

    int len=0;//子序列个数
    LIS[0]=-INF;
    for(int i=1;i<=n;i++){
        int l=0,r=len;
        //最大的小于num的数
        while(l<r){
            int mid = l+r+1>>1;
            if(LIS[mid]<num[i]) l=mid;
            else r=mid-1;
        }
        len=max(len,l+1);
        LIS[l+1]=num[i];
    }
    cout<<len;
    return 0;
}