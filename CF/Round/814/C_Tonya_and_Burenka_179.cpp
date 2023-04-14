#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=2e5+10;
int arr[N];
vector<LL> sum[N];
vector<pair<int,int>> link[N];
bool mark[N];

constexpr int M=N;
int prime[M],minp[M],idx;
bool isnp[M];

void get_prime(int n=M-1) {
    isnp[1]=minp[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) prime[++idx]=i,minp[i]=i;
        for(int j=1;prime[j]<=n/i;j++) {
            isnp[prime[j]*i]=true;
            minp[prime[j]*i]=prime[j];
            if(i%prime[j]==0) break;
        }
    }
}

vector<int> get_factor(int val) {
    vector<int> res;
    while(val>1) {
        int t=minp[val];
        res.push_back(t);
        while(minp[val]==t) val/=t;
    }
    return res;
}

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];

    multiset<LL> st;
    vector<int> g;
    for(int x:get_factor(n)) g.emplace_back(n/x);
    for(int x:g) {
        for(int i=1;i<=n;i++) mark[i]=0;
        sum[x].resize(x+1);
        for(int i=1,j=i+x;i<j;i++) {
            int t=i;
            while(!mark[t]) {
                mark[t]=1;
                link[t].emplace_back(x,i);
                sum[x][i]+=arr[t];
                t+=x;
                if(t>n) t-=n;
            }
            st.insert(sum[x][i]*x);
        }
    }

    cout<<*st.rbegin()<<endl;
    while(q--) {
        int pos,val;
        cin>>pos>>val;
        if(arr[pos]!=val) {
            int t=val-arr[pos];
            arr[pos]=val;
            for(auto [x,i]:link[pos]) {
                st.erase(st.find(sum[x][i]*x));
                sum[x][i]+=t;
                st.insert(sum[x][i]*x);
            }
        }
        cout<<*st.rbegin()<<endl;
    }

    for(int i=1;i<=n;i++) link[i].clear();
    for(int x:g) sum[x].clear();
}

int main() {
    get_prime();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}