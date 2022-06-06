#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
int ans=1e8;

void dfs(vector<int> state,int step){
    if(state.size()==1) {
        ans=min(ans,step);
        return;
    }
    for(int i=0;i<state.size();i++){
        debug(state.size());
        vector<int> tmp=state;
        auto it=tmp.begin()+i;
        if(it==tmp.begin()||it==tmp.end()-1){
            tmp.erase(it);
        }
        else {
            if(*prev(it)==*next(it)) tmp.erase(it,next(it));
            else tmp.erase(it);
        }
        dfs(tmp,step+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> num; 
    for(int i=0;i<n;i++){
        int in;
        cin>>in;
        if(num.size()&&num.back()==in) continue;
        num.push_back(in);
    }
    dfs(num,0);
    cout<<ans<<endl;
    return 0;
}