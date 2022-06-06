#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=100010;
int n,store[N];
ll ans;

int main(){
    cin>>n;
    int mid=n/2;
    for(int i=0;i<n;i++) cin>>store[i];
    sort(store,store+n);
    for(int i=0;i<n;i++){
        ans+=abs(store[i]-store[mid]);
    }
    cout<<ans;
    return 0;
}