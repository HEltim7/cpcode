#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

constexpr int N=3e5+10,INF=0x3f3f3f3f;
int lis[N];

int LIS(vector<int> &num) {
    memset(lis, 0, sizeof lis);
    int n=num.size()-1;
    int len=0;
    lis[len]=-INF;
    for(int i=1;i<=n;i++){
        int l=0,r=len,mid;
        while(l<r){
            mid=l+r+1>>1;
            if(lis[mid]<num[i]) l=mid;
            else r=mid-1;
        }
        len=max(len,l+1);
        lis[l+1]=num[i];
    }
    return len;
}

void solve() {
    vector<pair<int,int>> arr;
    int n;
    cin>>n;
    for(int i=1,a;i<=n;i++) {
        cin>>a;
        arr.push_back({a,0});
    }
    for(int i=1,b;i<=n;i++) {
        cin>>b;
        arr[i-1].second=b;
    }
    sort(arr.begin(),arr.end());
    int ans=0;
    vector<int> A(1),B(1);
    for(auto [a,b]:arr) A.push_back(a),B.push_back(b);
    ans=LIS(A)+LIS(B);
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}