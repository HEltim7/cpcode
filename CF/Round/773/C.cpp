#include<iostream>
#include<set>
#include<map>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        LL n,x;
        cin>>n>>x;
        map<LL,int> st;
        for(int i=1;i<=n;i++){
            LL in;
            cin>>in;
            if(st.find(in)!=st.end()) st.find(in)->second++;
            else st.insert({in,1});
        }
        for(auto &[a,b]:st){
            while(b){
                auto it=st.find(a*x);
                if(it!=st.end()&&it->second>0)
                    it->second--,b--;
                else break;
            }
        }
        int res=0;
        for(auto [a,b]:st) res+=b;
        cout<<res<<endl;
    }
    return 0;
}