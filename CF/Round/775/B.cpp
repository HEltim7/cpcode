#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
LL num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>num[i];
        sort(num+1,num+1+n);
        LL maxx=num[n];
        LL pre=0;
        for(int i=1;i<n;i++) pre+=num[i];
        if(maxx==0) cout<<0<<endl;
        else if(maxx<=pre+1) cout<<1<<endl;
        else cout<<maxx-pre<<endl;
    }
    return 0;
}