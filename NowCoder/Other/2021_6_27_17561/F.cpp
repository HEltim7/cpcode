#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define endl '\n'

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;


const int maxn=1e6+5;
bool vis[maxn];
int prime[maxn],mu[maxn];

void init_mu(int n){//init_mu(n) 就可得到1-n的莫比乌斯函数的值，存在mu中
    int cnt=0;
    mu[1]=1;
    for(int i=2;i<n;i++){
        if(!vis[i]){
            prime[cnt++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<cnt&&i*prime[j]<n;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j]==0)   {mu[i*prime[j]]=0;break;}
            else { mu[i*prime[j]]=-mu[i];}
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init_mu(maxn);
    int n;
    cin>>n;
    while(n--){
        int query;
        cin>>query;
        cout<<mu[query]<<endl;
    }
    return 0;
}