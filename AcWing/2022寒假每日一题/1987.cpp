#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
typedef vector<PII> VII;
const int N=1e5+10,INF=0x3f3f3f3f;
VII dif;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,in,idx=0;
    string dir;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>in>>dir;
        if(dir[0]=='L') in=idx-in;
        else in=idx+in;
        dif.emplace_back(min(in,idx),1);
        dif.emplace_back(max(in,idx),-1);
        idx=in;
    }
    dif.emplace_back(INF,0);
    sort(dif.begin(),dif.end());
    int ans=0,now=0,lasti=-INF;
    PII last={0,0};
    for(auto [i,x]:dif){
        if(i!=lasti){
            if(last.second>=2) ans+=lasti-last.first;
            last={lasti,now};
            lasti=i;
        }
        now+=x;
    }
    cout<<ans;
    return 0;
}