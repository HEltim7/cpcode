#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

const int N=2e5+10;
LL a[N],b[N],h[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int maxx=0,minx=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i]>>b[i]>>h[i];
            if(a[i]>=a[maxx]){
                minx=maxx;
                maxx=i;
            }
            else if(a[i]>a[minx]) minx=i;
        }
        LL res=0;
        for(int i=1;i<=n;i++){
            if(maxx==i) res+=max(a[minx]-b[i]-h[i]+1,0LL);
            else res+=max(a[maxx]-b[i]-h[i]+1,0LL);
        }
        cout<<res<<endl;
    }
    return 0;
}