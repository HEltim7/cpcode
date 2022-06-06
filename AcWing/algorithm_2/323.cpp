#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

#define endl '\n'

typedef vector<int> VI;
typedef pair<int,int> PII;
const int N=1510;
bool isson[N];

PII dfs(VI tree[],int node){
    PII ans;
    ans.first=1;
    for(int i:tree[node]){
        PII res=dfs(tree,i);
        ans.first+=min(res.first,res.second);
        ans.second+=res.first;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    while(cin>>n){
        memset(isson,0,sizeof isson);
        VI tree[N];
        for(int i=1;i<=n;i++){
            int id,num,son;
            char trash;
            cin>>id>>trash>>trash>>num>>trash;
            while(num--) cin>>son,tree[id].push_back(son),isson[son]=1;
        }
        int root=0;
        while(isson[root]) root++;

        PII ans=dfs(tree,root);
        cout<<min(ans.first,ans.second)<<endl;
    }
    return 0;
}