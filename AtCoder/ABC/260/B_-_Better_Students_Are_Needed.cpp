#include <functional>
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PII = pair<int,int>;
const int N=1e3+10;
int math[N],eng[N];
bool mark[N];

bool cmp(PII &a,PII &b) {
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}

void solve() {
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    vector<pair<int, int>> arr;
    for(int i=1;i<=n;i++) cin>>math[i],arr.emplace_back(math[i],i);
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<x;i++) mark[arr[i].second]=1;
    arr.clear();
    for(int i=1;i<=n;i++) cin>>eng[i],arr.emplace_back(eng[i],i);
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0,cnt=0;cnt<y;i++) if(!mark[arr[i].second]) mark[arr[i].second]=1,cnt++;
    arr.clear();
    for(int i=1;i<=n;i++) arr.emplace_back(math[i]+eng[i],i);
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0,cnt=0;cnt<z;i++) if(!mark[arr[i].second]) mark[arr[i].second]=1,cnt++;
    for(int i=1;i<=n;i++) if(mark[i]) cout<<i<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}