#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e2+10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t,n;
    cin>>t;
    int a[N];
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int x=0,y=0;
        for(int i=2;i<=n;i++) if(a[i]==0&&a[i-1]==1){
            x=i-1;
            break;
        } 
        for(int i=n-1;i>=1;i--) if(a[i]==0&&a[i+1]==1){
            y=i+1;
            break;
        }
        cout<<y-x<<endl;
    }
    return 0;
}