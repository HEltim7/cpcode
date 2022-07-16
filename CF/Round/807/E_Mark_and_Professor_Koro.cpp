#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=2e5+10;
int cnt[N],arr[N];
map<int,int> mp;

void del(int pos) {
    auto it=mp.lower_bound(pos);
    auto [l,r]=*it;
    if(r>=pos) {
        if(l!=pos) it->second=pos-1;
        else mp.erase(it);
        if(pos+1<=r) mp.emplace(pos+1,r);
    }
    else {
        assert(next(it)!=mp.end());
        auto [L,R]=*next(it);
        if(L==R) mp.erase(next(it));
        else mp.erase(next(it)),mp.emplace(L+1,R);
        if(r+1==pos) it->second=L-1; //merge
        else mp.emplace(pos,L-1);
    }
}

void add(int pos) {
    auto it=mp.lower_bound(pos);
    auto [l,r]=*it;
    if(r<pos) {
        if(r+1==pos) it->second++;
        else mp.emplace(pos,pos);
    }
    else {
        if(l==pos) mp.erase(it);
        else it->second=pos-1;
        mp.emplace(r+1,r+1);
    }
}

void solve() {
    int n,q,bit=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        cnt[arr[i]]++;
    }
    for(int i=1;i<N;i++) {
        if(cnt[i]) bit=max(bit,i);
        if(cnt[i]>=2) {
            cnt[i+1]+=cnt[i]/2;
            cnt[i]%=2;
        }
    }

    for(int i=1;i<N;i++) {
        if(cnt[i]) {
            if(mp.empty()) mp.emplace(i,i);
            else if(mp.rbegin()->second==i-1) mp.rbegin()->second=i;
            else mp.emplace(i,i);
        }
    }
    while(q--) {
        int k,v;
        cin>>k>>v;
        if(v>arr[k]) {
            add(v);
            del(arr[k]);
        }
        else {
            del(arr[k]);
            add(v);
        }
        arr[k]=v;
        cout<<mp.rbegin()->second<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}