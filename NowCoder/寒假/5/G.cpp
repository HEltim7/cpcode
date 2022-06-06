#include<iostream>
#include<cassert>
using namespace std;

#define endl '\n'
typedef long long LL;
int cnt[20];
LL ans;

void dfs(int deep,int sum){
    if(sum==6){
        ans++;
        return;
    }
    for(int i=deep;i<=13;i++){
        cnt[i]--;
        assert(cnt[i]>=0);
        if(cnt[i]>0) dfs(i,sum+1);
        else dfs(i+1,sum+1);
        cnt[i]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(int i=1;i<=13;i++) cnt[i]=4;
    dfs(1,0);
    cout<<ans;
    return 0;
}