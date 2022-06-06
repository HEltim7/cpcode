#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=110;
int arr[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) 
            cin>>arr[i];
        bool ans=1;
        int res=0;
        for(int i=n-1;i>=1;i--){
            while(arr[i]>=arr[i+1]&&arr[i]>0){
                arr[i]/=2;
                res++;
            }
            if(arr[i]>=arr[i+1]){
                ans=0;
                break;
            }
        }
        if(ans) cout<<res<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}