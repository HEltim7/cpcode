#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;
const int N=1e5+10;
ll ans;
int n;
int id[N],loc[N],altid[N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) id[i]=i;
    for(int i=1;i<=n;i++){
        cin>>altid[i];
        loc[altid[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(loc[i]==i) continue;
        if(i==altid[loc[i]]){
            ans+=1;
        }
        else ans+=2;
        
        int a=loc[i],b=loc[altid[i]];
        int c=altid[i],d=altid[loc[i]];

        loc[c]=a;
        loc[i]=b;
        altid[i]=d;
        altid[a]=c;

        // swap(loc[altid[i]],loc[i]);
        // swap(altid[loc[i]],altid[i])
    }
    cout<<ans;
    return 0;
}