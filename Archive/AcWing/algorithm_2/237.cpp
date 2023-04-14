#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;

const int N=2e5+10;
int fa[N];
int n;
int idx;
unordered_map<int,int> m;
vector<PII> v;

int findfa(int x){
    if(fa[x]==x) return x;
    else return fa[x]=findfa(fa[x]);
}

int getid(int num){
    if(m.find(num)==m.end()){
        m.emplace(num,++idx);
        return idx;
    }
    else return m.find(num)->second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,a,b,e;
    cin>>t;
    while(t--){
        idx=0;
        m.clear(),v.clear();
        cin>>n;
        for(int i=1;i<=2*n;i++) fa[i]=i;
        for(int i=1;i<=n;i++){
            cin>>a>>b>>e;
            a=getid(a),b=getid(b);
            if(e==1){
                a=findfa(a),b=findfa(b);
                fa[a]=fa[b];
            }
            else v.push_back({a,b});
        }
        bool conflict=0;
        for(auto i:v){
            a=findfa(i.first),b=findfa(i.second);
            if(a==b){
                conflict=1;
                break;
            }
        }
        if(conflict) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}