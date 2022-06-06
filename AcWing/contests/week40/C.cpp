#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    LL a,b;
    cin>>a>>b;
    multiset<int> st;
    while(a){
        st.insert(a%10);
        a/=10;    
    }
    vector<int> num;
    vector<int> ans;
    bool flag=1;
    while(b){
        num.push_back(b%10);
        b/=10;
    }
    if(st.size()<num.size()) flag=0;
    reverse(num.begin(),num.end());
    for(auto x:num){
        if(flag){
            auto it=st.upper_bound(x);
            if(it==st.begin()){
                for(int i=ans.size()-1;i>=0;i--){
                    auto tt=st.lower_bound(ans[i]);
                    if(tt!=st.begin()){
                        tt=prev(tt);
                        int tmp=ans[i];
                        ans[i]=*tt;
                        st.erase(tt);
                        st.insert(tmp);
                        break;
                    }
                    else{
                        st.insert(ans[i]);
                        ans.pop_back();
                    }
                }
                break;
            }
            it=prev(it);
            ans.push_back(*it);
            if(*it<x) flag=0;
            st.erase(it);
        }
        else{
            break;
        }
    }
    vector<int> tmp;
    for(auto x:st) tmp.push_back(x);
    while(tmp.size()) ans.push_back(tmp.back()) ,tmp.pop_back();
    for(auto x:ans) cout<<x;
    return 0;
}