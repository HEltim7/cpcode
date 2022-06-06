#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        LL n;
        cin>>n;
        int two=0;
        LL tmp=1;
        while(n%2==0) two++,n/=2,tmp*=2;
        if(n==1)
            cout<<"-1"<<endl;
        else if(two==0)
            cout<<"2"<<endl;
        else cout<<min(tmp*2,n)<<endl;
    }
    return 0;
}