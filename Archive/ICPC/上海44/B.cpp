#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e4+10;
string str[N];

inline LL code(string s){
    LL res=0;
    reverse(s.begin(),s.end());
    for(auto x:s) res=res*10+x-'0'+1;
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++) {
        cout<<"Case #"<<z<<": ";
        int n;
        cin>>n;
        set<LL> st;
        bool flag=0;
        for(int i=1;i<=n;i++){
            cin>>str[i];
            LL t=code(str[i]);
            if(st.find(t)!=st.end()) flag=1;
            st.insert(code(str[i]));
        }
        if(flag){
            cout<<"No"<<endl;
            continue;
        }
        bool ans=1;
        for(int i=1;i<=n&&ans;i++){
            string s;
            str[i].pop_back();
            for(auto x:str[i]){
                s.push_back(x);
                LL t=code(s);
                if(st.find(t)!=st.end()) ans=0;
            }
        }
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}