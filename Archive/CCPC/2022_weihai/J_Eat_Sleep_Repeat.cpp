#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=1e5+10;
int arr[N];
PII con[N];

LL solve(vector<PII> con,vector<int> arr) {
    if(arr.empty()) return 0;
    LL res=0;
    int pre=con.front().first+1;
    vector<int> low(arr.size());
    int idx=0;
    for(int i=1;i<con.size()&&idx<low.size();i++) {
        if(con[i].first==pre) {
            int cnt=con[i].second;
            while(idx<low.size()&&cnt) low[idx++]=con[i].first,cnt--;
            pre++;
        }
    }
    while(idx<low.size()) low[idx++]=pre;
    for(int i=0;i<arr.size();i++) res+=arr[i]-low[i];
    return res;
}

void solve() {
    int n,k;
    cin>>n>>k;
    multiset<int> st;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        st.insert(arr[i]);
    }
    bool flag=0;
    for(int i=1;i<=k;i++) {
        int x,y;
        cin>>x>>y;
        con[i]={x,y};
        if(st.count(x)>y) flag=1;
    }
    if(flag) {
        cout<<"FuuFuu"<<endl;
        return;
    }

    LL ans=0;
    sort(con+1,con+1+k);
    sort(arr+1,arr+1+n);
    vector<PII> cons(1,{-1,0});
    vector<int> arrs;
    int j=1;
    for(int i=1;i<=k&&j<=n;i++) {
        if(con[i].second==0) {
            while(j<=n&&arr[j]<con[i].first) {
                arrs.push_back(arr[j++]);
            }
            ans+=solve(cons,arrs);
            cons.clear();
            arrs.clear();
            cons.push_back(con[i]);
        }
        else {
            cons.push_back(con[i]);
        }
    }
    while(j<=n) arrs.push_back(arr[j++]);
    ans+=solve(cons,arrs);

    cout<<(ans&1?"Pico":"FuuFuu")<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}