#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int a[N],b[N];
int cnt[N],suf[N];

inline void move(int &idx){
    cnt[a[++idx]]++;
    suf[a[idx]]--;
}

void solve(){
    int n;
    cin>>n;
    memset(cnt,0,sizeof (int)*(n+1));
    memset(suf,0,sizeof (int)*(n+1));
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=n;i>=2;i--) suf[a[i]]++;
    cnt[a[1]]=1;
    for(int i=1,j=1;i<=n;){
        if(a[j]==b[i]) {
            cnt[a[j]]--;
            if(cnt[a[j]]==0) move(j);
            i++;
        }
        else{
            if(suf[a[j]]<=0){
                cout<<"NO"<<endl;
                return;
            }
            else move(j);
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}