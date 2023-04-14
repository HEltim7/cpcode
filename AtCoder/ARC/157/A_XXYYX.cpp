#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
int l[]={0,0,1,1};
int r[]={0,1,0,1};

void solve() {
    int n;
    int cnt[4];
    cin>>n>>cnt[0]>>cnt[1]>>cnt[2]>>cnt[3];
    if(n==1) cout<<"Yes";
    else if(n==3) {
        if(cnt[0]==1&&cnt[3]==1) cout<<"No";
        else cout<<"Yes";
    }
    else {
        int x=2*cnt[0]+cnt[1]+cnt[2];
        int y=2*cnt[3]+cnt[1]+cnt[2];
        
        auto check=[&](int p,int q) {
            return (x+p)%2==0&&(y+q)%2==0;
        };

        bool ans=0;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++) {
                if(i==j&&cnt[i]>=2||i!=j&&cnt[i]>=1&&cnt[j]>=1) {
                    int p=0,q=0;
                    if(l[i]) q++;
                    else p++;
                    if(r[j]) q++;
                    else p++;
                    ans|=check(p,q);
                }
            }
        if(ans) cout<<"Yes";
        else cout<<"No";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}