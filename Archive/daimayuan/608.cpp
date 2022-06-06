#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e6+10;
int cnt[N],arr[N],sum;
int mark[N];

inline void add(int x){
    if(++cnt[x]==1) sum++;
}

inline void del(int x){
    if(--cnt[x]==0) sum--;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i],add(arr[i]);
    vector<int> stk;
    for(int i=1;i<=n;i++){
        if(mark[arr[i]]) {
            del(arr[i]);
            continue;
        }
        while(!stk.empty()&&arr[i]<=stk.back()&&sum-(cnt[stk.back()]-1==0)>=m)
            mark[stk.back()]--,del(stk.back()),stk.pop_back();
        mark[arr[i]]++;
        stk.push_back(arr[i]);
    }
    for(int i=0;i<m;i++) cout<<stk[i]<<(i==m-1?"":" ");
    return 0;
}