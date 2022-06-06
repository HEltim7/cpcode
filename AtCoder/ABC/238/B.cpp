#include<iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int N=1010;
bool cut[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,idx=0;
    cin>>n;
    cut[360]=1;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        idx+=in;
        if(idx>360) idx-=360;
        cut[idx]=1;
    }
    int cnt=1,ans=0;
    for(int i=1;i<=360;i++){
        if(cut[i]) ans=max(ans,cnt),cnt=0;
        cnt++;
    }
    cout<<ans;
    return 0;
}