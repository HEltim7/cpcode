#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
constexpr int N=2e5+10,M=35;
int arr[N],cnt[N][M];

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        int x=arr[i];
        for(int j=0;j<M;j++) cnt[i][j]=cnt[i-1][j];
        while(x) {
            cnt[i][lowbit(x)]++;
            x-=lowbit(x);
        }
    }

    while(q--) {
        int l,r;
        cin>>l>>r;
        bool flag=1,zero=1;
        for(int i=0;i<M;i++) {
            int val=cnt[r][i]-cnt[l-1][i];
            if(val&1) {
                cout<<"-1"<<endl;
                flag=0;
                break;
            }
            else if(val) zero=0;
        }
        if(!flag) continue;

        if(zero) cout<<0<<endl;
        else if((r-l+1)%2) cout<<1<<endl;
        else {
            if(arr[l]==0||arr[r]==0) cout<<1<<endl;
            else {
                
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}