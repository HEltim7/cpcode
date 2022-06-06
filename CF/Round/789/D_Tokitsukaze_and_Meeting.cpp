#include<vector>
#include<iostream>
#include<algorithm>
#include<deque>
#include<cstring>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
const int N=1e6+10;
int tr[N];
int n,m;

inline void add(int pos,int val) {
    while(pos<=m) tr[pos]+=val,pos+=lowbit(pos);
}

inline void add(int l,int r,int val) {
    l=(l-1+m)%m+1,r=(r-1+m)%m+1;
    if(r>=l) {
        add(l,val);
        add(r+1,-val);
    }
    else {
        add(1,val);
        add(r+1,-val);
        add(l,val);
    }
}

inline int query(int pos) {
    int res=0;
    while(pos) res+=tr[pos],pos-=lowbit(pos);
    return res;
}

void solve() {
    cin>>n>>m;
    memset(tr,0,sizeof (int)*(m+1));
    deque<bool> dq(m,0);
    string s;
    cin>>s;
    int res=0,last=-1,one=-1;
    for(int i=0;i<s.size();i++) {
        int k=s[i]=='1';
        int col=i%m+1;
        int t=dq.back();
        dq.pop_back();
        dq.push_front(t|k);
        if(!t&&k) res++;

        if(k) {
            int len=i-last-1;
            if(one==-1) one=i;
            if(last==-1) last=i;
            else if(len>=m) {
                int cnt=len%m;
                add(col-cnt-1,col-1,len/m);
                if(cnt+1<m) add(col,col-cnt-1-1,len/m-1);
            }
            last=i;
        }
        int ans=0;
        if(last!=-1) ans=((i-one)/m+1)-(i-last)/m-query(col);
        cout<<res+ans<<" \n"[i+1==s.size()];
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