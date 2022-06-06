#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int,int> PII;
const int N=3e5+10;

vector<int> alls;
vector<PII> add,query;

int num[N];

int find(int x){
    int l=0,r=alls.size()-1;
    while(l<r){
        int mid=l+r>>1;
        if(alls[mid]>=x) r=mid;
        else l=mid+1;
    }
    return r+1;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m,l,r,x,c;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    for(int i=1;i<=m;i++){
        cin>>l>>r;
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    for(auto item:add){
        num[find(item.first)]+=item.second;
    }
    for(int i=1;i<=alls.size();i++) num[i]+=num[i-1];
    for(auto item:query){
        l=find(item.first),r=find(item.second);
        cout<<num[r]-num[l-1]<<'\n';
    }
    return 0;
}