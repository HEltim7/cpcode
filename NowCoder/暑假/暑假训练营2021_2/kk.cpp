#include <iostream>
#include <set>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
#define fi first
#define se second

typedef pair<int,int> pii;

const int N=1e6+10;
int a[N];
int chafen[N];//差分
int loc[N];//位置映射
int ans[N];
set <pii> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,k;
    cin>>n>>k;
    int t1,t2;
    for(int i=1;i<=k;i++){
        cin>>t1>>t2;
        s.emplace(t1,t2);
    }

    int maxx=0,idx=0;
    for(auto x:s){
        int need=x.second-maxx;
        if(need>x.first-idx){
            cout<<-1;
            return 0;
        }
        //递增情况
        if(x.second>maxx){
            for(int i=x.first-idx-need;i>0;i--) a[++idx]=n;
            while(idx<x.first) a[++idx]=++maxx,loc[maxx]=idx;
        }
        //递减/等于情况
        else{
            int newmax=x.second;
            int find_old_max=loc[newmax];
            chafen[find_old_max]++;

            //中间填充n
            while(idx<x.first-1) a[++idx]=n;

            a[++idx]=newmax;
            loc[newmax]=idx;
            chafen[idx]--;
        }
    }

    while(idx<n) a[++idx]=n;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=chafen[i];
        a[i]+=sum;
    }

    for(int i=1;i<=n;i++) a[i]=min(a[i],n);

    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    return 0;
}
/////////////////////改范围