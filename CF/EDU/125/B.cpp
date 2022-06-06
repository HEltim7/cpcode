#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        LL B,x,y,sum=0,cur=0;
        cin>>n>>B>>x>>y;
        for(int i=1;i<=n;i++){
            if(cur+x<=B) cur+=x,sum+=cur;
            else cur-=y,sum+=cur;
        }
        cout<<sum<<endl;
    }
    return 0;
}