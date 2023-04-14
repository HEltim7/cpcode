#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

#define endl '\n'
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
const int N=1e5+10;

VI mark[N];
bool island[N];
int idx,ans=1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    memset(island,1,sizeof (bool)*(n+1));
    island[0]=0;
    VII read;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        read.emplace_back(in,i);
    }
    sort(read.begin(),read.end());
    for(int i=0;i<read.size();i++){
        auto [a,b]=read[i];
        if(!i||a!=read[i-1].first) idx++;
        mark[idx].push_back(b);
    }

    for(int i=1,res=1;i<=idx;i++){
        for(auto x:mark[i]){
            island[x]=0;
            res--;
            if(island[x-1]) res++;
            if(island[x+1]) res++; 
        }
        ans=max(ans,res);
    }
    cout<<ans;
    return 0;
}