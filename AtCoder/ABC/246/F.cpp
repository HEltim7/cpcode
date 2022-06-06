#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;
const int N=20,mod=998244353;
string str[N];
vector<int> difnum[N];
int dif[N];
int cnt[N][1<<7];

inline LL qpow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1) res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,l;
    cin>>n>>l;
    for(int i=0;i<n;i++){
        cin>>str[i];
        for(auto x:str[i])
            if(++cnt[i][x]==1) 
                dif[i]++,difnum[i].push_back(x);
    }

    LL ans=0;
    vector<int> num[2];
    for(int i=1;i<(1<<n);i++){
        int pre=-1,cur=0,bitcnt=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                bitcnt++;
                if(pre==-1) {
                    num[cur]=difnum[j];
                    pre=0,cur=1;
                }
                else{
                    num[cur].clear();
                    for(auto x:num[pre])
                        if(cnt[j][x]) 
                            num[cur].push_back(x);
                    swap(pre,cur);
                }
            }
        }
        LL res=qpow(num[pre].size(),l)%mod;
        if(!(bitcnt&1)) res=(res*-1+mod)%mod;
        ans=(ans+res)%mod;
    }
    cout<<ans;
    return 0;
}