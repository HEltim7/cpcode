#include <cmath>
#include<iostream>
#include <numeric>
#include <vector>

using namespace std;
using ll=long long;
const int N = (1<<15) +10;

int qmi(int a,int b,int p) {
    int ans=1;
    for(; b; b>>=1, a=1ll*a*a%p)
        if(b&1) ans=1ll*ans*a%p;
    return ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector<int> z(N), prm;
    z[1]=1;
    for(int i=2; i<N; ++i) {
        if(!z[i]) prm.push_back(i);
        for(int p:prm) {
            if(i>(N-1)/p) break;
            z[i*p]=1;
            if(i%p==0) break;
        }
    }

    // for(int i=0; i<20; ++i) {
    //     cerr<<prm[i]<<" ";
    // }
    // cerr<<"\n";

    int t=1;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0; i<n; ++i) {
            cin>>a[i];
        }

        int ok = 1;
        int g=0;
        int ma=0;
        for(int i=0; i<n; ++i) {
            ma=max(ma, a[i]);
            if(i<=29 and (1<<i)<a[i]) {
                ok=0;
                break;
            }

            if(g==0) {
                g=(1<<i)-a[i];
            }else {
                g=gcd(g, (0ll+qmi(2,i,g)-a[i]%g+g)%g);
            }
        }
        // cerr<<g<<endl;

        // M|a[i]

        if(!ok || g<=ma) {
            cout<<"-1\n";
        }
        else if(g==1) {
            cout<<1<<"\n";
        }
        else {
            int mp=-1;
            for(int x:prm)
                if(g%x==0) {
                    mp=x;
                    break;
                }
            if(mp==-1) mp=g;
            if(g/mp<=ma) {
                cout<<g<<"\n";
            }else {
                cout<<"-1\n";
            }
        }
    }
    return 0;
}