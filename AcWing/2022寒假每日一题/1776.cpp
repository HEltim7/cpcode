#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=210;
int n,m;
string cow[N];
bool st[1<<7];

bool check(int idx){
    st['A']=st['C']=st['G']=st['T']=0;
    for(int i=1;i<=n;i++) st[cow[i][idx]]=1;
    for(int i=n+1;i<=n+n;i++){
        if(st[cow[i][idx]])
            return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n+n;i++) cin>>cow[i];
    for(int i=0;i<m;i++) if(check(i)) ans++;
    cout<<ans;
    return 0;
}