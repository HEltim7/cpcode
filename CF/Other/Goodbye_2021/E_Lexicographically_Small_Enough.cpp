#include<set>
#include<array>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;

template<typename T,std::size_t N> 
struct Fenwick {
    vector<int> tr=vector<int>(N,0);

    int lowbit(int x) { return x&(-x); }

    void update(T &aim,T &val) {
        aim+=val;
    }

    void add(std::size_t pos,T val) {
        while(pos<=N) update(tr[pos],val),pos+=lowbit(pos);
    }

    T query(std::size_t pos) {
        T res=0;
        while(pos) update(res,tr[pos]),pos-=lowbit(pos);
        return res;
    }
};

void solve() {
    int n;
    LL ans=0;
    string s,t;
    Fenwick<int,N> tr;
    array<bool,N> mark;
    set<pair<char,int>> st;
    cin>>n>>s>>t;
    string tmp=s;
    sort(tmp.begin(),tmp.end());
    if(tmp>=t) {
        cout<<"-1"<<endl;
        return;
    }
    memset(mark.begin(),0,sizeof (bool)*(n+1));
    for(int i=0;i<n;i++) st.emplace(s[i],i);

    for(int i=0,j=0;j<n;j++) {
        if(mark[i]) {
            i++;
            continue;
        }
        if(s[i]<t[j]) break;
        if(st.begin()->first<t[j]) {
            int pos;
            for(int j=i+1;j<n;j++) 
                if(s[j]<t[j]) {
                    pos=j;
                    break;
                }
            ans+=pos-i+tr.query(pos);
            break;
        }
        if(s[i]>t[j]) {
            if(st.begin()->first<=t[j]) {
                auto [ch,pos]=*st.begin();
                ans+=pos-i+tr.query(pos);
                mark[pos]=1;
                st.erase(st.begin());
                tr.add(pos+1,-1);
            }
        }
        else {
            mark[i]=1;
            st.erase({s[i],i});
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}