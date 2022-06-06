#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

using LL=long long;
const int N=1e3+10;
bool st[N];
int n,m;

void output() {
    cout<<"? ";
    for(int i=1;i<=m;i++) cout<<st[i];
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin>>n>>m;
    vector<pair<int,int>> lens;
    for(int i=1;i<=m;i++) {
        st[i]=1;
        output();
        int in;
        cin>>in;
        lens.emplace_back(in,i);
        st[i]=0;
    }
    sort(lens.begin(),lens.end(),greater<pair<int,int>>());

    for(int i=1;i<=m;i++) st[i]=1;
    output();
    int ans=0;
    cin>>ans;
    for(int i=0;i<m-1;i++) {
        auto [l,id]=lens[i];
        st[id]=0;
        output();
        int in;
        cin>>in;
        if(ans-in==l||in>ans) st[id]=1;
        else ans=in;
    }
    cout<<"! "<<ans<<endl;
    return 0;
}