#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    if(a==b) {
        int ans=0,pre=0,suf=0;
        for(int i=0,len=0;i<n;i++) {
            int j=i;
            while(j+1<n&&a[j+1]>=a[j]) j++;
            len=j-i+1;
            if(len>ans) {
                ans=len;
                pre=i;
                suf=j;
            }
            i=j;
        }
        cout<<pre+1<<' '<<suf+1<<endl;
    }
    else {
        int pre=0,suf=0;
        for(int i=0;i<n;i++) {
            if(a[i]!=b[i]) {
                pre=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(a[i]!=b[i]) {
                suf=i;
                break;
            }
        }
        sort(a.begin()+pre,a.begin()+suf+1);

        while(pre-1>=0&&a[pre]>=a[pre-1]) pre--;
        while(suf+1<n&&a[suf]<=a[suf+1]) suf++;
        cout<<pre+1<<' '<<suf+1<<endl;
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