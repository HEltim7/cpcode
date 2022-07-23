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
    int siz=0,poped=0,idx=0;
    for(auto x:s){
        if(x.second>x.first-poped){
            cout<<-1;
            return 0;
        }
        
        //特判没有pop的情况
        if(x.second==x.first+poped){
            while(siz+poped<x.first) a[++idx]=++siz;
            continue;
        }

        //特判减少
        if(x.second<=siz){
            while(idx<x.first-1) a[++idx]=x.second+1;
            a[++idx]=x.second;
            continue;
        }

        while(siz<x.second-1) a[++idx]=++siz;
        while(siz+poped<x.first-1) a[++idx]=siz+2,poped++;
        a[++idx]=++siz;
        
    }
    for(int i=siz+poped;i<=n;i++) a[++idx]=i;
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    return 0;
}