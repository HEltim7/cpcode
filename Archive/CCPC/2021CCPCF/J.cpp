#include <array>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int L=5;
using S=array<char,L>;
vector<S> haf;

void solve() {
    int n;
    cin>>n;

    vector<S> pre(n),suf(n);
    vector<int> lim(n);
    for(int i=0;i<n;i++) {
        string s;
        cin>>s>>lim[i];
        lim[i]/=10;
        pre[i]={s[0],s[1],s[2],s[3],s[4]};
        suf[i]={s[5],s[6],s[7],s[8],s[9]};
    }

    vector<array<int,L+1>> tr;
    vector<int> cnt;
    tr.reserve(n*1024+10);
    cnt.reserve(n*1024+10);

    auto new_node=[&]() {
        tr.emplace_back();
        cnt.emplace_back();
        return tr.size()-1;
    };
    new_node();

    auto ins=[&](const vector<int> &v) {
        int u=0;
        for(int x:v) {
            if(!tr[u][x]) tr[u][x]=new_node();
            u=tr[u][x];
            cnt[u]++;
        }
    };

    auto sam=[&](const S &x,const S &y) {
        int res=0;
        for(int i=0;i<L;i++) res+=x[i]==y[i];
        return res;
    };

    for(const S &x:haf) {
        vector<int> res(n);
        bool valid=true;
        for(int i=0;i<n;i++) {
            res[i]=sam(x,suf[i]);
            if(res[i]>lim[i]) {
                valid=false;
                break;
            }
        }
        if(valid) ins(res);
    }

    int ans=0;
    for(const S &x:haf) {
        vector<int> res(n);
        bool valid=true;
        for(int i=0;i<n;i++) {
            res[i]=lim[i]-sam(x,pre[i]);
            if(res[i]<0||res[i]>L) {
                valid=false;
                break;
            }
        }

        if(!valid) continue;
        int u=0;
        for(int i=0;i<n;i++) {
            if(!tr[u][res[i]]) break;
            u=tr[u][res[i]];
            if(i+1==n) ans+=cnt[u];
        }
    }
    cout<<ans<<endl;
}

int main() {
    for(char a='A';a<='D';a++)
        for(char b='A';b<='D';b++)
            for(char c='A';c<='D';c++)
                for(char d='A';d<='D';d++)
                    for(char e='A';e<='D';e++)
                        haf.emplace_back(S({a,b,c,d,e}));

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}