#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<unordered_set>
using namespace std;

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
const int N=2e5+10;
int maxx[N],cnt[N];
vector<PII> nums[N];

void solve() {
    int n;
    cin>>n;
    vector<int> num;
    for(int i=1;i<=n;i++) {
        int m;
        cin>>m;
        for(int j=1;j<=m;j++) {
            int p,e;
            cin>>p>>e;
            num.push_back(p);
            nums[i].push_back({p,e});
        }
        sort(nums[i].begin(),nums[i].end());
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=1;i<=n;i++) 
        for(auto &[p,e]:nums[i])
            p=lower_bound(num.begin(),num.end(),p)-num.begin()+1;
    for(int i=1;i<=n;i++)
        for(auto [p,e]:nums[i]) {
            if(maxx[p]==e) cnt[p]++;
            else if(maxx[p]<e) maxx[p]=e,cnt[p]=1;
        }
    
    set<string> st;
    for(int i=1;i<=n;i++) {
        string res;
        for(auto [p,e]:nums[i]) {
            if(e==maxx[p]&&cnt[p]==1)
                res+=to_string(p)+","+to_string(e)+"|";
        }
        st.insert(res);
    }
    cout<<st.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}