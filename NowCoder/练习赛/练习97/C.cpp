#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
int num[N],p[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    vector<int> change[N];
    int res[2]={0};
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        if(num[i]>0) res[in]+=num[i];
        if(num[i]-p[i]>0) change[in^1].push_back(num[i]-p[i]);
    }
    sort(change[0].begin(),change[0].end(),greater<int>());
    sort(change[1].begin(),change[1].end(),greater<int>());
    for(int i=0;i<=1;i++)
        for(int j=0;j<min(m,(int)change[i].size());j++)
             res[i]+=change[i][j];
    cout<<max(res[0],res[1]);
    return 0;
}