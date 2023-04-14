#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int a[N],b[N],val[N];

template<typename T=int> struct Fenwick {
    int size=0;
    vector<T> tr;

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,const T &val) { aim+=val; }

    void add(int pos,T val) {
        while(pos<=size) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(int pos) {
        T res{};
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }

    Fenwick(int size):size(size) { tr.resize(size+1); }
};
Fenwick<> tr(N);

void solve() {
    int n;
    cin>>n;
    vector<int> va,vb;
    for(int i=1;i<=n;i++) cin>>a[i],va.push_back(a[i]);
    for(int i=1;i<=n;i++) cin>>b[i],vb.push_back(b[i]);
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());
    if(va!=vb) {
        cout<<"No"<<endl;
        return;
    }

    va.erase(unique(va.begin(),va.end()),va.end());
    if(va.size()!=n) {
        cout<<"Yes"<<endl;
        return;
    }

    for(int i=1;i<=n;i++) val[a[i]]=i;
    for(int i=1;i<=n;i++) b[i]=val[b[i]];

    int cnt=0;
    for(int i=1;i<=n;i++) {
        cnt+=i-1-tr.query(b[i]);
        tr.add(b[i], 1);
    }

    if(cnt&1) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}