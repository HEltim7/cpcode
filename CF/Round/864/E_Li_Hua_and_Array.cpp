#include <set>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10,block=200;
constexpr int M=5e6+10;
int arr[N],maxx[N],jump[N],blen[N],L[N],R[N];

int prime[M],euler[M],idx;
bool isnp[M];

void get_prime(int n=M-1) {
    isnp[1]=euler[1]=1;
    for(int i=2;i<=n;i++) {
        if(!isnp[i]) prime[++idx]=i,euler[i]=i-1;
        for(int j=1;prime[j]<=n/i;j++) {
            isnp[prime[j]*i]=true;
            if(i%prime[j]==0) {
                euler[i*prime[j]]=euler[i]*prime[j];
                break;
            }
            else euler[i*prime[j]]=euler[i]*(prime[j]-1);
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    set<int> st;
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        if(arr[i]>1) st.insert(i);
    }

    auto bf=[&](int l,int r) {
        int maxx=arr[l];
        int cnt=0,len=1;
        for(int i=l+1;i<=r;i++,len++) {
            int cur=arr[i];
            while(cur!=maxx) {
                if(cur>maxx) {
                    cur=euler[cur];
                    cnt++;
                }
                else {
                    maxx=euler[maxx];
                    cnt+=len;
                }
            }
        }
        return make_pair(maxx,cnt);
    };

    auto getid=[&](int x) {
        return x/block;
    };

    for(int id=0,l=1,r=min(n,block-1);l<=n;id++) {
        L[id]=l,R[id]=r;
        blen[id]=r-l+1;
        tie(maxx[id],jump[id])=bf(l,r);
        l=r+1;
        r=min(n,r+block);
    }

    while(m--) {
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1) {
            auto it=st.lower_bound(l);
            while(it!=st.end()&&*it<=r) {
                int idx=*it;
                int id=getid(idx);
                int t=euler[arr[idx]];
                if(t<maxx[id]) {
                    maxx[id]=t;
                    jump[id]+=blen[id]-1;
                }
                else jump[id]--;
                arr[idx]=t;

                if(t==1) it=st.erase(it);
                else it++;
            }
        }
        else {
            if(getid(l)==getid(r)) {
                auto [maxl,cnt]=bf(l,r);
                cout<<cnt<<endl;
            }
            else {
                int maxl,cnt;
                tie(maxl,cnt)=bf(l,R[getid(l)]);
                auto [x,y]=bf(L[getid(r)],r);
                cnt+=y;

                auto merge=[&](int &max1,int len1,int max2,int len2) {
                    while(max1!=max2) {
                        if(max1>max2) {
                            max1=euler[max1];
                            cnt+=len1;
                        }
                        else {
                            max2=euler[max2];
                            cnt+=len2;
                        }
                    }
                };

                int lenl=R[getid(l)]-l+1;
                int lenr=r-L[getid(r)]+1;
                merge(maxl, lenl, x, lenr);
                lenl+=lenr;

                for(int i=getid(l)+1;i<getid(r);i++) {
                    cnt+=jump[i];
                    merge(maxl,lenl,maxx[i],blen[i]);
                    lenl+=blen[i];
                }
                cout<<cnt<<endl;
            }
        }
    }
}

int main() {
    get_prime();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}