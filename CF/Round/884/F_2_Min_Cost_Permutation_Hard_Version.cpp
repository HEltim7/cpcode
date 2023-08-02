#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e3+10;
LL arr[N];

void solve() {
    int n;
    LL c;
    cin>>n>>c;
    for(int i=1;i<=n;i++) cin>>arr[i];
    
    if(c>=0) sort(arr+1,arr+1+n);
    else sort(arr+1,arr+1+n,greater<>());

    if(c>=0) {
        for(int i=1;i<=n;i++) cout<<arr[i]<<" \n"[i==n];
        return;
    }

    auto cal=[&](LL x,LL y) {
        return abs(y-x-c);
    };

    auto get=[&](int l,int r) {
        LL res=0;
        for(int i=l+1;i<=r;i++) {
            res+=cal(arr[i-1],arr[i]);
        }
        return res;
    };

    LL minn=get(1,n);
    LL cur=minn;
    LL sum=0;

    for(int i=1;i<=n;i++) {
        auto work=[&](int j,bool apply) {
            int h=i-1;
            int l=h+1;
            int r=j-1;
            int suf=j+1;

            if(l!=j) {
                if(h) {
                    cur-=cal(arr[h],arr[l]);
                    cur+=cal(arr[h],arr[j]);
                }
                cur-=cal(arr[r],arr[j]);
                cur+=cal(arr[j],arr[l]);
                if(suf<=n) {
                    cur-=cal(arr[j],arr[suf]);
                    cur+=cal(arr[r],arr[suf]);
                }
            }

            if(cur==minn) {
                if(apply) {
                    LL tmp=arr[j];
                    for(int i=r;i>=l;i--) arr[i+1]=arr[i];
                    arr[l]=tmp;
                }
                return true;
            }

            else cur=minn;
            return false;
        };

        int l=i,r=n;
        while(l<r) {
            int mid=(l+r+1)/2;
            if(work(mid,0)) l=mid;
            else r=mid-1;
        }
        work(l, 1);
    }

    for(int i=1;i<=n;i++) cout<<arr[i]<<" \n"[i==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}