#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=2e5+10;
int heap[N],bak[N];
int n;

bool check(int mid) {
    memcpy(heap,bak,sizeof (int)*(n+1));
    for(int i=n;i>=3;i--){
        if(heap[i]<mid) return 0;
        int t=min(bak[i],heap[i]-mid)/3;
        heap[i-1]+=t;
        heap[i-2]+=2*t;
    }
    return heap[1]>=mid&&heap[2]>=mid;
}

void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>bak[i];
    int l=1,r=1e9;
    while(l<r) {
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    cout<<l<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}