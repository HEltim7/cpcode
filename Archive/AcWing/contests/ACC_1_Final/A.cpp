#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e6+10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    LL a,b,c,d;
    cin>>a>>b>>c>>d;
    LL x=b,y=d;
    unordered_set<LL> st;
    LL pre=b;
    for(int i=1;i<N;i++){
        st.insert(pre);
        pre+=a;
    }
    pre=d;
    int ans=-1;
    for(int i=1;i<N;i++){
        if(st.find(pre)!=st.end()){
            ans=pre;
            break;
        }
        pre+=c;
    }
    cout<<ans;
    return 0;
}