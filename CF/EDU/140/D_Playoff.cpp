#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;

    for(int i=1,tot=1<<n;i<=tot;i++) {
        int lmax=i-1,lmin=lmax;
        int rmax=tot-i,rmin=rmax;
        int left=tot;
        bool flag=1;

        for(auto x:s) {
            left/=2;
            if(x=='1') {
                if(lmax==0) {
                    flag=0;
                    break;
                }
                lmax=(lmax-1)/2;
                rmin=left-lmax-1;
                lmin=max(0,lmin-left);
                rmax=left-lmin-1;
            }
            else {
                if(rmax==0) {
                    flag=0;
                    break;
                }
                rmax=(rmax-1)/2;
                lmin=left-rmax-1;
                rmin=max(0,rmin-left);
                lmax=left-rmin-1;
            }
        }
        
        if(flag) cout<<i<<' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}