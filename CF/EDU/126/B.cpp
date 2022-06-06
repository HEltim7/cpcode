#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int mod=32768;
int ans[mod+10];

void bfs(){
    queue<pair<int,int>> q;
    q.push({0,0});
    while(q.size()){
        auto [h,step]=q.front();
        q.pop();
        int pre=(h-1+mod)%mod;
        if(ans[pre]>step+1){
            ans[pre]=step+1;
            q.emplace(pre,step+1);
        }
        if(h%2==0){
            pre=h/2;
            if(ans[pre]>step+1){
                ans[pre]=step+1;
                q.emplace(pre,step+1);
            }

            pre=(h+mod)/2;
            if(ans[pre]>step+1){
                ans[pre]=step+1;
                q.emplace(pre,step+1);
            }
        }
    }
}

int main() {
    memset(ans,0x3f,sizeof ans);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    ans[0]=0;
    bfs();
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        cout<<ans[in]<<' ';
    }
    return 0;
}