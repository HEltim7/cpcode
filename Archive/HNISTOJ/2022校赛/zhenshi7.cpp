#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

vector<vector<string>> res;
vector<string> cur;
bool mark[10];
int n,m;

void dfs(int deep){
    if(deep>m-n){
        res.push_back(cur);
        return;
    }
    for(int i=0;i<=m-n;i++){
        if(!mark[i]){
            mark[i]=1;
            cur.push_back(to_string(i+n));
            dfs(deep+1);
            mark[i]=0;
            cur.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m;
    dfs(0);
    sort(res.begin(),res.end());
    for(auto x:res){
        for(auto y:x)
            cout<<y<<' ';
        cout<<endl;
    }
    return 0;
}