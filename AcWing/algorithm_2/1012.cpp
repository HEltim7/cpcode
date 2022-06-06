#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=5e3+10;
int lis[N];
struct CITY
{
    int a;
    int b;
} city[N];

bool cmp(CITY A,CITY B){
    return A.a<B.a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>city[i].a>>city[i].b;
    sort(city+1,city+1+n,cmp);

    for(int i=1;i<=n;i++){
        lis[i]=1;
        for(int j=1;j<i;j++) if(city[i].b>city[j].b) lis[i]=max(lis[i],lis[j]+1);
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,lis[i]);
    cout<<ans;
    return 0;
}