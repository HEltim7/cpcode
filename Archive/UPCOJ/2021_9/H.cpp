#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;
const int N=1e5+10;
int res,ans[N];

int main(){
    for(int i=1;i<=N;i++){
        int tmp=sqrt(i);
        if(tmp*tmp==i) res++;
        ans[i]=res;
    }
    int a,b;
    while(cin>>a>>b&&(a||b)){
        cout<<ans[b]-ans[a-1]<<'\n';
    }
    return 0;
}