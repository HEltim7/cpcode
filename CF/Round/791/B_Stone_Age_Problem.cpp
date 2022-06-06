#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
using PLI=pair<LL,int>;
const int N=2e5+10;

PLI arr[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,q;
    LL sum=0;
    int val,tim=0;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i].first,sum+=arr[i].first;
    for(int i=1;i<=q;i++){
        int t;
        cin>>t;
        if(t==1){
            int idx;
            LL x;
            cin>>idx>>x;
            if(arr[idx].second<tim) arr[idx]={val,tim};
            sum+=x-arr[idx].first;
            arr[idx].first=x;
        }
        else {
            LL x;
            cin>>x;
            sum=x*n;
            val=x,tim=i;
        }
        cout<<sum<<endl;
    }
    return 0;
}
