#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef vector<int> VI;
typedef pair<int,int> PII;
const int N=1e5;
PII cow[N+10];
VI pre[N*2+10];

inline int cal(int a,int b){
    return abs(cow[a].first-cow[b].first);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,ans=0,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char b;
        cin>>x>>b;
        if(b=='H') cow[i]={x,1};
        else cow[i]={x,-1};
    }
    sort(cow+1,cow+1+n);
    int lastp=0;
    for(int i=1;i<=n;i++) 
        if(cow[i].second==cow[i-1].second) ans=max(ans,cow[i].first-lastp);
        else lastp=cow[i].first;
    for(int i=1;i<=n;i++) 
        sum+=cow[i].second,pre[sum+N].push_back(i);
    if(pre[N].size()) ans=max(ans,cal(pre[N].back(),1));
    for(int i=1;i<=N*2;i++){
        if(pre[i].size()>=2)
            ans=max(ans,cal(pre[i].back(),pre[i].front()+1));
    }
    cout<<ans;
    return 0;
}