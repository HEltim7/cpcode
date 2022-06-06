#include<iostream>
#include<set>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e3+10;
vector<int> adj[30];
bool mark[30];
int cnt[30];

void dfs(int x){
    mark[x]=1;
    for(int s:adj[x])
        if(!mark[s]) dfs(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        for(int i=0;i<str.size();i++){
            int t=str[i]-'a'+1;
            cnt[t]=1;
            if(i) adj[str[i-1]-'a'+1].push_back(t),
                    adj[t].push_back(str[i-1]-'a'+1);
        }
    }
    int ans=0;
    for(int i=1;i<=26;i++) if(cnt[i]&&!mark[i]) dfs(i),ans++;
    cout<<ans;
    return 0;
}