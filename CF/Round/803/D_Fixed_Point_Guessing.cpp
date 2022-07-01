#include<vector>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

using LL=long long;
const int N=1e4+10,M=15;
int arr[N];
int qcnt;

bool query(int l,int r) {
    assert(++qcnt<=M);
    cout<<"? "<<l<<' '<<r<<endl;
    int cnt=0;
    for(int i=l;i<=r;i++) {
        int in;
        cin>>in;
        if(in>=l&&in<=r) cnt++;
    }
    return cnt&1;
}

void solve() {
    qcnt=0;
    int n;
    cin>>n;
    int l=1,r=n;
    while(l<r) {
        int mid=l+r>>1;
        if(query(l,mid)) r=mid;
        else l=mid+1;
    }
    cout<<"! "<<l<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}