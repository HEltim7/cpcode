#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define endl '\n'
map<int,vector<int>> m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        if(m.find(in)==m.end()){
            vector<int> x={i};
            m.insert({in,x});
        }
        else m[in].push_back(i);
    }
    for(int i=1;i<=q;i++){
        int x,k;
        cin>>x>>k;
        if(m.find(x)!=m.end()&&m[x].size()>=k)
            cout<<m[x][k-1]<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}