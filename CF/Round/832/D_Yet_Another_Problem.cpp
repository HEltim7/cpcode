#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N],pre[N];
set<int> not_zero;
map<int,set<int>> pos[2];

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        pre[i]=arr[i]^pre[i-1];
        if(arr[i]) not_zero.insert(i);
        auto &cur=pos[i&1];
        auto it=cur.find(pre[i]);
        if(it==cur.end()) cur.insert({pre[i],{i}});
        else it->second.insert(i);
    }

    while(q--) {
        int l,r,len;
        cin>>l>>r;
        len=r-l+1;
        auto it=not_zero.lower_bound(l);
        if(it==not_zero.end()||*it>r) cout<<0<<endl;
        else if(pre[r]^pre[l-1]) cout<<-1<<endl;
        else if(len&1||arr[l]==0||arr[r]==0) cout<<1<<endl;
        else if(len==2) cout<<-1<<endl;
        else {
            auto &cur=pos[l&1];
            auto it=cur.find(pre[l-1]);
            if(it==cur.end()) cout<<-1<<endl;
            else {
                auto &st=it->second;
                auto itt=st.lower_bound(l);
                if(itt==st.end()||*itt>r) cout<<-1<<endl;
                else cout<<2<<endl;
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