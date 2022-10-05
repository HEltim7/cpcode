#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e3+10,K=21;
int arr[N][K];
LL val[N];
map<LL,int> st;

void solve() {
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) {
            cin>>arr[i][j];
            val[i]=val[i]*10+arr[i][j];
        }
        st.insert({val[i],i});
    }

    LL ans=0;
    for(int i=1;i<=n;i++) {
        LL res=0;
        for(int j=1;j<=n;j++) {
            LL s=0;
            if(i==j) continue;
            for(int c=1;c<=k;c++) {
                if(arr[i][c]==arr[j][c])
                    s=s*10+arr[i][c];
                else s=s*10+3-arr[i][c]-arr[j][c];
            }
            auto it=st.find(s);
            if(it!=st.end()&&it->second!=i&&it->second<j) res++;
        }
        ans+=(res*(res-1))/2;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}