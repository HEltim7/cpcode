#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int N=1e3+10;

map<string,int> names;
map<string,int> cnt;
string entry[N][N];
vector<string> query;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        string name;
        cin>>name;
        names.insert({name,i});
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) 
            cin>>entry[i][j],entry[i][j]+='|';
    string cmd,tmp;
    for(int i=1;i<=7;i++) cin>>cmd;
    for(auto x:cmd){
        if(x==','||x==';') query.push_back(tmp),tmp.clear();
        else tmp+=x;
    }
    for(int i=1;i<=n;i++){
        string line;
        for(auto j:query){
            line+=entry[i][names[j]];
        }
        if(cnt.find(line)==cnt.end())
            cnt.insert({line,1});
        else cnt[line]++;
    }
    cout<<cnt.size()<<endl;
    for(auto [line,res]:cnt) cout<<res<<' ';
    return 0;
}