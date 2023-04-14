#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e2+10;
int arr[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>arr[i];
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j++)
                for(int k=j;k<=n;k++)
                    if(arr[i]+arr[j]==arr[k]) ans++;
        cout<<ans<<endl;
    }
    return 0;
}