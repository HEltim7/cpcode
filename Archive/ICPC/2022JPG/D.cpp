#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=5e3+10;
int dp[N][N],arr[N];

template<typename T=int,T init=T{}> struct Fenwick {
    int size=0;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) { aim=max(aim,val); }

    void add(int pos,T val) {
        while(pos<=size) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res=init;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    void reset(int pos) {
        while(pos<=size) tr[pos]=init,pos+=lowbit(pos);
    }
    
    Fenwick(int size=N):size(size) { tr.resize(size+1,init); }
};
Fenwick<> tr[N];

void solve() {
    int n,ans=1;
    cin>>n;
    vector<int> num;
    for(int i=1;i<=n;i++) cin>>arr[i],num.push_back(arr[i]);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) 
        arr[i]=lower_bound(num.begin(),num.end(),arr[i])-num.begin()+2;
    
    tr[1].add(1, 1);
    for(int i=2;i<=n;i++) {
        tr[i].add(1, 1);
        for(int j=1;j<i;j++) {
            dp[i][j]=tr[j].query(arr[i]-1)+1;
            tr[i].add(arr[j], dp[i][j]);
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}