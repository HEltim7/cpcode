#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e6+10;
int arr[N],tmp[N];
bool mark[N];
int edp[N],ne[N],pre[N];

void solve() {
    int n,pos=-1;
    cin>>n;
    for(int i=0;i<n;i++) cin>>tmp[i];
    for(int i=0;i<n;i++) if((tmp[i]+1)%3!=tmp[(i+1)%n]) pos=i;
    if(pos==-1) {
        cout<<"Yes"<<endl;
        return;
    }
    else {
        int idx=0;
        for(int i=pos+1;i<n;i++) arr[idx++]=tmp[i];
        for(int i=0;i<=pos;i++) arr[idx++]=tmp[i];
    }

    int cnt=1;
    edp[n-1]=n-1;
    for(int i=0;i<n;i++) ne[i]=(i-1+n)%n;
    for(int i=0;i<n;i++) pre[ne[i]]=i;
    for(int i=n-1,j=i;i>=1;i--) {
        if(arr[i-1]==arr[i]||(arr[i-1]+1)%3==arr[i]) edp[j]=i-1;
        else edp[i-1]=i-1,j=i-1,cnt++;
    }

    int idx=n-1;
    auto del=[&](int x) {
        int mid=edp[x];
        int l=ne[mid];
        int r=pre[mid];
        pre[l]=r;
        ne[r]=l;
        if(arr[l]==arr[r]||(arr[l]+1)%3==arr[r]) {
            edp[x]=edp[l];
            cnt--;
        }
        else edp[x]=r;
    };

    memset(mark, 0, sizeof(bool)*(n+1));
    while(cnt>1) {
        if(mark[idx]) {
            cout<<"No"<<endl;
            return;
        }
        if(edp[idx]!=idx) del(idx);
        else mark[idx]=1,idx=ne[idx];
    }
    cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}