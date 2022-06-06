#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;
int arr[N*2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>arr[i],arr[i+n]=arr[i];
            if(arr[i]==1) cnt++;
        }
        if(cnt!=1) cout<<"NO"<<endl;
        else{
            bool ans=1;
            for(int i=1;i<2*n;i++)
                if(arr[i+1]-arr[i]>1)
                    ans=0;
            if(ans) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}