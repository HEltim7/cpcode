#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define fi first
#define se second
typedef pair<int,int> PII;
const int N=1e5+10;
int ans[N];
int h[N];
PII c[N];

bool cmp1(PII a,PII b){
    return a.first<b.first;
}

bool cmp2(PII a,PII b){
    return a.second<b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        c[i].fi=i;
        cin>>c[i].se;
    }
    for(int i=1;i<=m;i++){
        cin>>h[i];
    }
    sort(c+1,c+1+n,cmp2);
    sort(h+1,h+1+m);

    for(int i=1,j=1;i<=n&&j<=m;){
        if(c[i].second>=h[j]) ans[i]++,j++;
        else i++;
    }

    for(int i=1;i<=n;i++) c[i].second=ans[i];

    sort(c+1,c+1+n,cmp1);
    for(int i=1;i<=n;i++) cout<<c[i].second<<endl;
    return 0;
}