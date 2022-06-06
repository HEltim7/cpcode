#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=110;
typedef long long LL;
int bit[N],rbit[N];
int n,l;

inline void count(int x){
    for(int i=0;i<=l;i++)
        if(x&(1<<i)) bit[i]++;
        else rbit[i]++;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>l;
        memset(bit,0,sizeof bit);
        memset(rbit,0,sizeof bit);
        for(int i=1;i<=n;i++){
            LL in;
            cin>>in;
            count(in);
        }
        LL ans=0;
        for(int i=0;i<=l;i++)
            if(rbit[i]<bit[i])
                ans+=1<<i;
        cout<<ans<<endl;
    }
    return 0;
}