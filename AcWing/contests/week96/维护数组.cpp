#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;

template<typename T=int> struct Fenwick {
    int size=0;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) { aim+=val; }

    void add(int pos,T val) {
        pos+=5;
        while(pos<=size) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        pos+=5;
        T res{};
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    Fenwick(int size):size(size) { tr.resize(size+1); }
};
Fenwick<LL> tra(N),trb(N);

int arr[N];

void solve() {
    int n,k,a,b,q;
    cin>>n>>k>>a>>b>>q;
    
    while(q--) {
        int op;
        cin>>op;
        if(op==1) {
            int x,y;
            cin>>x>>y;

            int val=min(arr[x]+y,b)-min(arr[x],b);
            trb.add(x, val);

            val=min(arr[x]+y,a)-min(arr[x],a);
            tra.add(x, val);

            arr[x]+=y;
        }
        else {
            int p;
            cin>>p;
            LL ans=0;
            ans+=trb.query(p-1);
            ans+=tra.query(tra.size)-tra.query(p+k-1);
            cout<<ans<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}