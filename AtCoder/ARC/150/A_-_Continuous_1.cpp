#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=3e5+10;
int pre[N];

void solve() {
    int n,k;
    string s;
    cin>>n>>k>>s;
    s=" "+s;

    for(int i=1;i<=n;i++) pre[i]=s[i]!='0';
    for(int i=1;i<=n;i++) pre[i]+=pre[i-1];
    
    int L=-1,R=-1;
    for(int i=1;i<=n;i++) if(s[i]=='1') {
        L=i;
        break;
    }
    for(int i=n;i>=1;i--) if(s[i]=='1') {
        R=i;
        break;
    }
    if(L==-1) {
        int cnt=0;
        for(int i=k;i<=n;i++)
            if(pre[i]-pre[i-k]==k) cnt++;
        if(cnt==1) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else {
        if(R-L+1>k) cout<<"No"<<endl;
        else {
            for(int i=L;i<=R;i++) {
                if(s[i]=='0') {
                    cout<<"No"<<endl;
                    return;
                }
            }

            int cnt=0;
            for(int i=max(k,R);i<=min(n,L+k-1);i++) 
                if(pre[i]-pre[i-k]==k) cnt++;
            if(cnt==1) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}