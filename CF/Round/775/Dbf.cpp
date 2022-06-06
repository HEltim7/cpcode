#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
using namespace std;

#define endl '\n'
typedef long long LL;
vector<int> tmp;
int maxv,len;

bool check(vector<int> &v){
    set<int> st;
    for(auto x:tmp) st.insert(x);
    for(int i=0;i<v.size();i++)
        for(int j=i;j<v.size();j++)
            if(st.find(v[j]/v[i])==st.end()) return 0;
    return 1;
}

void dfs(int start,int num){
    if(start>=len){
        if(check(tmp)) {
            for(auto x:tmp) cout<<x<<' ';
            cout<<endl;
        }
        return ;
    }
    for(int i=num;i<=maxv;i++) {
        tmp[start]=i;
        dfs(start+1,i+1);
    }
}

int main() {
    freopen64("in1.txt","r",stdin);
    freopen64("std.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n,c;
        cin>>n>>c;
        tmp=vector<int>(n);
        for(int i=0;i<n;i++) cin>>tmp[i];
        if(check(tmp)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}