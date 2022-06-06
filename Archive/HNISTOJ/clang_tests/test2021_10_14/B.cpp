#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

typedef vector<int> VI;
const int N=110;
unordered_map<int,VI> map;
int n,m;
int in[N];
bool passed[N];

bool topsort(){
    queue<int> q;
    for(int i=1;i<=n;i++) if(in[i]==0) q.push(i);
    while(q.size()){
        int h=q.front();
        passed[h]=1;
        for(auto x:map.find(h)->second){
            in[x]--;
            if(in[x]==0) q.push(x);
        }
        q.pop();
    }
    for(auto x:map) if(!passed[x.first]) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        map.emplace(x,VI());
    }
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        auto v=map.find(a);
        v->second.push_back(b);
        in[b]++;
    }
    if(topsort()) cout<<"yes";
    else cout<<"no";
    return 0;
}