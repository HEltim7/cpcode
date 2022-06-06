#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
const int N=55;
bool st[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n,in;
    cin>>t;
    while(t--){
        memset(st,0,sizeof st);
        cin>>n;
        bool ans=1;
        for(int i=1;i<=n;i++){
            cin>>in;
            while(in>n) in/=2;
            for(;;){
                if(in<=0) break;
                if(!st[in]){
                    st[in]=1;
                    break;
                }
                else in/=2;
            }
        }
        for(int i=1;i<=n;i++) if(!st[i]){
            ans=0;
            break;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}