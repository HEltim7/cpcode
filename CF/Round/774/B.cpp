#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e5+10;
LL num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>num[i];
        sort(num+1,num+1+n);
        LL red=0,blue=0;
        red=num[1];
        bool flag=0;
        for(int i=2,j=n;i<j;i++,j--){
            red+=num[i];
            blue+=num[j];
            if(blue>red){
                flag=1;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}