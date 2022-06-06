#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int ch[N];

void solve(){
    int n;
    cin>>n;
    memset(ch,0,sizeof (int)*(n+1));
    for(int i=1;i<n;i++){
        int p;
        cin>>p;
        ch[p]++;
    }
    vector<int> arr;
    for(int i=1;i<=n;i++) if(ch[i]) arr.push_back(ch[i]);
    arr.push_back(1);
    sort(arr.begin(),arr.end());
    priority_queue<int> heap;
    for(int i=0;i<arr.size();i++) 
        if(arr[i]-i-1>0)
            heap.push(arr[i]-i-1);
    
    int ans=arr.size();
    int pre=0;
    while(heap.size()){
        pre++;
        int h=heap.top();
        heap.pop();
        if(h>=pre) ans++;
        h-=1;
        if(h>pre) heap.push(h);
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}
/*

1
10
1 1 1 1 2 2 2 2 2

1
9
1 1 1 2 2 2 2 2

*/