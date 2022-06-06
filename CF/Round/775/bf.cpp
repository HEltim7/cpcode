#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
int maxv,len;
vector<vector<int>> res;
vector<int> tmp;

void dfs(int start,int num){
    if(start>=len){
        res.push_back(tmp);
        return ;
    }
    for(int i=num;i<=maxv;i++) {
        tmp[start]=i;
        dfs(start+1,i+1);
    }
}

int main() {
    freopen64("in1.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>maxv>>len;
    tmp=vector<int>(len);
    dfs(0,1);
    cout<<res.size()<<endl;
    for(auto x:res) {
        cout<<len<<' '<<maxv<<endl;
        for(auto y:x) cout<<y<<' ';
        cout<<endl;
    }
    return 0;
}