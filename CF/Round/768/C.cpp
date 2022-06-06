#include<iostream>
#include<cstring>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=65536+10;
bool st[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        memset(st,1,sizeof (bool)*(n+1));
        if(n==4&&k==3){
            cout<<-1<<endl;
            continue;
        }
        if(k==0){
            for(int i=0;i<n;i++){
                if(st[i]){
                    cout<<i<<' '<<n-1-i<<endl;
                    st[i]=st[n-1-i]=0;
                }
            }
        }
        else if(k==n-1){
            cout<<n-1<<' '<<n-1-1<<endl;
            cout<<1<<' '<<3<<endl;
            cout<<0<<' '<<n-1-3<<endl;
            st[n-1]=st[n-1-1]=0;
            st[1]=st[3]=0;
            st[0]=st[n-1-3]=0;
            for(int i=0;i<n;i++){
                if(st[i]){
                    cout<<i<<' '<<n-1-i<<endl;
                    st[i]=st[n-1-i]=0;
                }
            }
        }
        else{
            cout<<n-1<<' '<<k<<endl;
            cout<<0<<' '<<n-1-k<<endl;
            st[n-1]=st[k]=0;
            st[0]=st[n-1-k]=0;
            for(int i=0;i<n;i++){
                if(st[i]){
                    cout<<i<<' '<<n-1-i<<endl;
                    st[i]=st[n-1-i]=0;
                }
            }
        }
    }
    return 0;
}