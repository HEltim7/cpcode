#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e3+10;
int cnt[N];

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> arr;
    set<pair<int,int>> st;
    st.emplace(1,n);
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        arr.emplace_back(a,b);
        for(int j=a;j<=b;j++) cnt[j]++;
    }
    for(int i=1;i<=n;i++){
        auto [a,b]=*st.begin();
        int idx=-1;
        for(int j=a;j<=b;j++) if(--cnt[j]==0) idx=j;
        st.erase(st.begin());
        if(idx!=a) st.emplace(a,idx-1);
        if(idx!=b) st.emplace(idx+1,b);
        cout<<a<<' '<<b<<' '<<idx<<endl;
    }
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}