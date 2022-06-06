#include<iostream>
using namespace std;

typedef long long ll;
const int N=1e3+10;
ll patience[N],ranks[N];
ll rounds;
int n,leave,tail;
int ans[N],cnt;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>patience[i];
    tail=n;
    for(int i=1;i<=n;i++) ranks[i]=i;
    while(tail>0){
        leave=0;
        rounds=-1;
        for(int i=1;i<=n;i++){
            if(patience[i]<=0) continue;
            ll tmp=(patience[i]-1)/ranks[i]+1;
            if(rounds==-1) rounds=tmp;
            else rounds=min(tmp,rounds);
        }
        for(int i=1;i<=n;i++){
            if(patience[i]<=0) continue;
            patience[i]-=(rounds-1)*ranks[i];
        }
        for(int i=1;i<=n;i++){
            if(patience[i]<=0) continue;
            ranks[i]-=leave;
            patience[i]-=ranks[i];
            if(patience[i]<=0){
                leave++;
                ans[++cnt]=i;
            }
        }
        tail-=leave;
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}