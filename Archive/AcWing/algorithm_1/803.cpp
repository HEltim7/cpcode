#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef pair<int,int> PII;
const int N=1e5+10;
vector<PII> chunk;
int ans=1;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    int l,r;
    PII in,now;
    for(int i=1;i<=n;i++){
        cin>>in.first>>in.second;
        chunk.push_back(in);
    }
    sort(chunk.begin(),chunk.end());
    now=chunk.front();
    for(int i=0;i<chunk.size();i++){
        if(chunk[i].second<=now.second) continue;
        if(chunk[i].first<=now.second) now.second=chunk[i].second;
        else now=chunk[i],ans++;
    }
    cout<<ans;
    return 0;
}