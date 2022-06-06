#include<iostream>
using namespace std;

#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string in;
    int t,a,b,k;
    int cnt[1<<7];
    cin>>t;
    while(t--){
        cin>>k>>k>>in;
        a=b=0;
        for(char i='a';i<='z';i++) cnt[i]=0;
        for(auto x:in) cnt[x]++;
        for(auto i='a';i<='z';i++) a+=cnt[i]/2*2,b+=cnt[i]%2;
        int ans=a/k;
        a-=ans*k;
        if(ans%2==0&&(a+b)/k) ans++;
        cout<<ans<<endl;
    }
    return 0;
}