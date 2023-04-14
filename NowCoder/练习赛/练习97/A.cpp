#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> odd,even,mark,res;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        if(in&1) odd.push_back(in);
        else even.push_back(in);
        mark.push_back(in);
    }
    sort(odd.begin(),odd.end());
    sort(even.begin(),even.end());
    int l=0,r=0;
    for(auto x:mark){
        if(x&1) res.push_back(odd[l++]);
        else res.push_back(even[r++]);
    }
    bool flag=1;
    for(int i=1;i<res.size();i++) if(res[i]<res[i-1]) flag=0;
    if(flag) cout<<"Yes";
    else cout<<"No";
    return 0;
}