#include <set>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
using TIII=tuple<int,int,int>;
constexpr int N=2e5+10,M=1e9;
tuple<int,int,int,int> res[N];

void solve() {
    int n;
    cin>>n;
    vector<TIII> sgl[3],dbl;
    for(int i=1;i<=n;i++) {
        int u,l,d,r;
        cin>>u>>l>>d>>r;
        if(u==d) sgl[u].emplace_back(l,r,i);
        else dbl.emplace_back(l,r,i);
    }

    set<PII> st;
    sort(sgl[1].begin(),sgl[1].end());
    sort(sgl[2].begin(),sgl[2].end());
    sort(dbl.begin(),dbl.end());

    int ans=0;
    for(int z=1;z<=2;z++) {
        st.clear(),st.emplace(0,0),st.emplace(M+1,M+1);
        for(int i=0,l,r,id;i<sgl[z].size();i++) {
            if(i==0) tie(l,r,id)=sgl[z].front();
            else {
                auto [L,R,ID]=sgl[z][i];
                if(L<=r+1) r=max(r,R);
                else st.emplace(l,r),l=L,r=R;
            }
            if(i+1==sgl[z].size()) st.emplace(l,r);
        }
        
        for(int i=0;i<dbl.size();) {
            auto [l,r,id]=dbl[i];
            auto it=--st.upper_bound({l,M});
            auto [L,R]=*it;
            if(R>=r) {
                sgl[z^3].emplace_back(l,r,id);
                swap(dbl[i],dbl.back());
                dbl.pop_back();
            }
            else i++;
        }
    }

    sort(dbl.begin(),dbl.end());
    st.clear(),st.emplace(0,0),st.emplace(M+1,M+1);
    for(int i=0,l,r,id;i<dbl.size();i++) {
        if(i==0) {
            tie(l,r,id)=dbl[i];
            res[id]={1,l,2,r};
        }
        else {
            auto [L,R,ID]=dbl[i];
            if(R<=r) res[ID]={0,0,0,0};
            else if(L<=r) res[ID]={1,r+1,2,R},r=R;
            else res[ID]={1,L,2,R},st.emplace(l,r),ans+=(r-l+1)*2,l=L,r=R;
        }
        if(i+1==dbl.size()) st.emplace(l,r),ans+=(r-l+1)*2;
    }

    for(int z=1;z<=2;z++) {
        for(int i=0;i<sgl[z].size();) {
            auto &[l,r,id]=sgl[z][i];
            auto it=st.upper_bound({l,M});
            auto [L,R]=*prev(it);
            if(l>=L&&r<=R) {
                res[id]={0,0,0,0};
                swap(sgl[z][i],sgl[z].back());
                sgl[z].pop_back();
            }
            else {
                l=max(l,R+1);
                r=min(r,it->first-1);
                i++;
            }
        }
    }

    for(int z=1;z<=2;z++) {
        sort(sgl[z].begin(),sgl[z].end());
        for(int i=0,l,r,id;i<sgl[z].size();i++) {
            if(i==0) {
                tie(l,r,id)=sgl[z][i];
                res[id]={z,l,z,r};
            }
            else {
                auto [L,R,ID]=sgl[z][i];
                if(R<=r) res[ID]={0,0,0,0};
                else if(L<=r) res[ID]={z,r+1,z,R},r=R;
                else res[ID]={z,L,z,R},ans+=r-l+1,l=L,r=R;
            }
            if(i+1==sgl[z].size()) ans+=r-l+1;
        }
    }

    cout<<ans<<endl;
    for(int i=1;i<=n;i++) {
        auto [u,l,d,r]=res[i];
        cout<<u<<' '<<l<<' '<<d<<' '<<r<<endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}