#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e3+10,M=1e6+10;
bool st[M];
int primes[M],idx;
int ans[N][N];

void init(int n) {
    st[1]=1;
    for(int i=2;i<=n;i++) {
        if(!st[i]) primes[idx++]=i;
        for(int j=0;primes[j]<=n/i;j++) {
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
    }
}

void solve() {
    int n;
    cin>>n;
    set<int> odd,even;
    vector<pair<int,int>> p;
    for(int i=1;i<=n*n;i++)
        if(i&1) odd.insert(i);
        else even.insert(i);

    auto output=[&]() {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cout<<ans[i][j]<<" \n"[j==n];
    };

    auto getp=[&](int cnt) {
        for(int i=1;i<=cnt;i++) {
            int o=*odd.begin();
            odd.erase(odd.begin());
            for(auto e:even) {
                if(st[e+o]) {
                    p.emplace_back(e,o);
                    even.erase(e);
                    break;
                }
            }
        }
    };

    if(n&1) {
        odd.erase(1);
        odd.erase(7);
        even.erase(2);
        even.erase(8);
        int midr=n/2;
        int midc=(n+1)/2;
        ans[midr][midc]=8;
        ans[midr][midc+1]=1;
        ans[midr+1][midc]=7;
        ans[midr+1][midc-1]=2;

        getp(n-2);
        for(int i=1;i<midr;i++) {
            ans[i][midc]=p.back().first;
            ans[i][midc+1]=p.back().second;
            p.pop_back();
        }
        for(int i=midr+2;i<=n;i++) {
            ans[i][midc-1]=p.back().first;
            ans[i][midc]=p.back().second;
            p.pop_back();
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++) {
                if(!ans[i][j]) {
                    if(j<midc) {
                        ans[i][j]=*even.begin();
                        even.erase(even.begin());
                    }
                    else {
                        ans[i][j]=*odd.begin();
                        odd.erase(odd.begin());
                    }
                }
            }
        output();
    }
    else {
        getp(n);
        for(int i=1;i<=n;i++) {
            ans[i][n/2]=p.back().first;
            ans[i][n/2+1]=p.back().second;
            p.pop_back();
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<n/2;j++) {
                ans[i][j]=*even.begin();
                even.erase(even.begin());
            }
            for(int j=n/2+2;j<=n;j++) {
                ans[i][j]=*odd.begin();
                odd.erase(odd.begin());
            }
        }
        output();
    }
}

int main() {
    init(1e6);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}