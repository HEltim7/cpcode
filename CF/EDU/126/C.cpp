#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=3e5+10;
int tr[N];

LL cal(int n,int maxx){
    LL odd=0,even=0;
    for(int i=1;i<=n;i++){
        int t=maxx-tr[i];
        if(t&1) odd++;
        even+=t/2;
    }
    if(odd>even) return odd*2-1;

    LL k=(even-odd)/3;
    even-=k;
    odd+=2*k;
    LL ans=max(even*2,odd*2-1);
    even--;
    odd+=2;
    ans=min(ans,max(even*2,odd*2-1));
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int maxx=0;
        for(int i=1;i<=n;i++){
            cin>>tr[i];
            maxx=max(maxx,tr[i]);
        }
        cout<<min(cal(n,maxx),cal(n,maxx+1))<<endl;
    }
    return 0;
}