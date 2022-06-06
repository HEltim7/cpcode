#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int lidx[N],ridx[N],arr[N];
LL pre[N],st[2][20][N];

void init_rng(int n) {
    vector<int> stk;
    for(int i=1;i<=n;i++) {
        while(stk.size()&&arr[i]>=arr[stk.back()]) stk.pop_back();
        lidx[i]=stk.empty()?1:stk.back()+1;
        stk.push_back(i);
    }
    stk.clear();
    for(int i=n;i>=1;i--) {
        while(stk.size()&&arr[i]>=arr[stk.back()]) stk.pop_back();
        ridx[i]=stk.empty()?n:stk.back()-1;
        stk.push_back(i);
    }
}

void init_st(int n) {
    for(int i=1,len=2;len<=n;i++,len*=2)
        for(int l=0,r=l+len-1;r<=n;l++,r++) {
            st[0][i][l]=min(st[0][i-1][l],st[0][i-1][l+len/2]);
            st[1][i][l]=max(st[1][i-1][l],st[1][i-1][l+len/2]);
        }
}

LL query(bool type,int l,int r) {
    int bit=0,len=1;
    while(len*2<=r-l+1) len*=2,bit++;
    if(type) return max(st[type][bit][l],st[type][bit][r-len+1]);
    return min(st[type][bit][l],st[type][bit][r-len+1]);
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
        cin>>arr[i],pre[i]=st[0][0][i]=st[1][0][i]=pre[i-1]+arr[i];
    init_rng(n),init_st(n);
    for(int i=1;i<=n;i++) {
        LL rmax=query(1,i,ridx[i]);
        LL lmin=query(0,lidx[i]-1,i-1);
        if(rmax-lmin>arr[i]) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}