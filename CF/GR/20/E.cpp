#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e3;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,in;
    cin>>n;
    int l=n+n-1,r=N*N+N-1;
    while(l<r){
        int mid=l+r>>1;
        cout<<"? "<<mid<<endl<<flush;
        cin>>in;
        if(in==1) r=mid;
        else l=mid+1;
    }
    int ans=l;
    int sum=l+1;
    for(int i=1;i<=n;i++){
        int aera=sum-i;
        int col=(aera+i-1)/i;
        assert(col>0);
        cout<<"? "<<col<<endl<<flush;
        cin>>in;
        if(in) ans=min(ans,in*col);
    }
    cout<<"! "<<ans<<endl<<flush;
    return 0;
}