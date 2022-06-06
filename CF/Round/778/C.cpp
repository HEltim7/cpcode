#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
LL cake[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        LL sum=0;
        cin>>n;
        multiset<LL> st;
        for(int i=1;i<=n;i++) 
            cin>>cake[i],sum+=cake[i],st.insert(cake[i]);
        vector<LL> pieces(1,sum);
        bool ans=1;
        while(pieces.size()){
            LL h=pieces.back();
            pieces.pop_back();
            if(h<*st.lower_bound(-1)) {
                ans=0;
                break;
            }
            auto it=st.find(h);
            if(it!=st.end()) st.erase(it);
            else{
                pieces.push_back(h/2);
                pieces.push_back((h+1)/2);
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}