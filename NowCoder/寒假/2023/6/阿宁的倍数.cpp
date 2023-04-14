#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=4e5+10;
int arr[N],cnt[N],ans[N];

void func(int x) {
    for(int i=1;i*i<=x;i++) {
        if(x%i==0) {
            cnt[i]++;
            if(x/i!=i) cnt[x/i]++;
        }
    }
}

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    vector<tuple<int,int,int,int>> query;

    int qid=0;
    for(int i=1;i<=q;i++) {
        int op,x;
        cin>>op>>x;
        if(op==1) arr[++n]=x;
        else {
            query.emplace_back(n,arr[x],1,++qid);
            query.emplace_back(x,arr[x],-1,qid);
        }
    }
    sort(query.begin(),query.end());

    int idx=0;
    for(auto &[pos,val,sign,id]:query) {
        while(idx<pos) func(arr[++idx]);
        ans[id]+=sign*cnt[val];
    }
    for(int i=1;i<=qid;i++) cout<<ans[i]<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}