#include<iostream>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
int num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        set<int> st;
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>num[i];
            st.insert(num[i]);
        }
        int idx=1;
        while(idx<=n&&st.size()){
            ans++;
            int maxx=num[idx];
            st.erase(num[idx]);
            for(int i=idx+1;i<=n;i++){
                auto it=st.upper_bound(0);
                if(*it>maxx){
                    idx=i;
                    break;
                }
                maxx=max(maxx,num[i]);
                st.erase(num[i]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}