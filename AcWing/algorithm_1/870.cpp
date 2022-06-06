#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define pb push_back

const int M=1e9+7;
const int N=5e4;
vector<int> num;
int res[N],ans=1;

int fn(int n){
    for(int i=2;i<=n/i;i++){
        while(n%i==0){
            num.pb(i);
            n/=i;
        }
    }
    if(n>1) num.pb(n);
}

int main(){
    int c,n;
    cin>>c;
    while(c--){
        cin>>n;
        fn(n);
    }
    sort(num.begin(),num.end());
    int t=-1,cnt=0;
    for(auto x:num){
        if(t==x) res[cnt]++;
        else{
            t=x;
            res[++cnt]++;
        }
    }
    for(int i=1;i<=cnt;i++) ans=ans*res[i]%M;
    cout<<ans;
}