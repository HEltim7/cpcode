#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define lowbit(x) (x&(-x))
using LL=long long;

inline bool check(int a,int b){
    int t=a^b;
    while(t&&a){
        if((t&1)&&(a&1)) return 0;
        t>>=1,a>>=1;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int c=a,res=0;
        while(!check(c,b)) res+=lowbit(c),c+=lowbit(c);
        if(c<b) res++;

        int ans=1e7;
        for(int i=b;i<=b*2;i++){
            c=a|i;
            ans=min(ans,c-i+1+(i-b));
        }
        cout<<min(ans,res)<<endl;
    }
    return 0;
}