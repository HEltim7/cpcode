#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;
LL a[N],b[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int k=0;
    set<LL> sta,stb;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]+=a[i-1];
        // sta.insert(a[i]);
    }
    for(int i=1;i<=m;i++) {
        cin>>b[i];
        b[i]+=b[i-1];
        // stb.insert(b[i]);
    }
    for(int l=1,r=1;l<=n&&r<=m;){
        if(a[l]==b[r]){
            k++;
            l++,r++;
        }
        else if(a[l]<b[r]) l++;
        else r++;
    }
    cout<<k;
    return 0;
}