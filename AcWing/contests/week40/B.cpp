#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e4+10;
int num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>num[i];
    sort(num+1,num+1+n);
    int idx=-1,res=0;
    for(int i=1;i<=n;i++){
        if(num[i]<=num[i-1]){
            res+=(num[i-1]-num[i]+1);
            num[i]=num[i-1]+1;
        }
    }
    cout<<res;
    return 0;
}