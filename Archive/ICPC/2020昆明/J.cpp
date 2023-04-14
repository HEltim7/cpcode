#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_set>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<PII> VII;
typedef vector<int> VI;
const int N=1e5+10;
int num[N];
map<int,int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(num[i]!=i) mp.insert({i,num[i]});
    }
    vector<VII> ans;
    int idx=0;
    while(mp.size()){
        unordered_set<int> mark;
        VI del;
        VII nex;
        VII cur;
        for(auto [x,y]:mp){
            if(mark.find(x)!=mark.end()||mark.find(y)!=mark.end()) continue;
            mark.insert(x);
            mark.insert(y);
            cur.push_back({x,y});
            del.push_back(y);
            del.push_back(x);
            if(x!=mp[y]) nex.push_back({x,mp[y]});
        }
        for(auto x:del) mp.erase(x);
        for(auto x:nex) mp.insert(x);
        ans.push_back(cur);
    }
    cout<<ans.size()<<endl;
    for(auto x:ans){
        cout<<x.size()<<' ';
        for(auto [y,z]:x)
            cout<<y<<' '<<z<<' ';
        cout<<endl;
    }
    return 0;
}