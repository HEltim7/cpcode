#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=2e3+10;
int cow[N];
int n,ans=0x3f3f3f3f,sum;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) 
        cin>>cow[i],sum+=cow[i],cow[i+n]=cow[i];

    for(int i=0;i<n;i++){
        int res=0,add=sum;
        for(int j=i+1;j<i+n;j++){
            add-=cow[j-1];
            res+=add;
        }
        ans=min(ans,res);
    }
    cout<<ans;
    return 0;
}