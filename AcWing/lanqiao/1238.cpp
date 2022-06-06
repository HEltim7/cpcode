#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+10;
const int MAX=1e5;
struct qwq
{
    int t;
    int id;
} like[N];

int n,k,d;
int head[N],t[N],sum[N],nexe[N],idx;
int lastlike[N];

bool cmp(qwq a,qwq b){
    return a.t<b.t;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    memset(lastlike,-1,sizeof lastlike);
    memset(nexe,-1,sizeof nexe);
    memset(head,-1,sizeof head);
    cin>>n>>d>>k;
    for(int i=1;i<=n;i++) cin>>like[i].t>>like[i].id;
    sort(like+1,like+1+n,cmp);
    for(int i=1;i<=n;i++){
        int tt=like[i].t,idd=like[i].id;
        t[idx]=tt;
        if(lastlike[idd]!=-1){
            nexe[lastlike[idd]]=idx;
            sum[idx]=sum[lastlike[idd]];
        }
        else{
            head[idd]=idx;
        }
        sum[idx]++;
        lastlike[idd]=idx++;
    }
    for(int i=0;i<=MAX;i++){
        for(int x=head[i],y=-1;x!=-1;x=nexe[x]){
            if(y==-1&&t[head[i]]+d<=t[x]) y=head[i];
            while(y!=-1&&t[nexe[y]]+d<=t[x]) y=nexe[y];
            if(y!=-1){
                if(sum[x]-sum[y]>=k){
                    cout<<i<<endl;
                    break;
                }
            }
            else if(sum[x]>=k){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}