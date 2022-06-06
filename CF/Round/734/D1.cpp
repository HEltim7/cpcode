#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        if(n%2==0&&m%2==0){
            if(k%2==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            if(n==1){
                if(k==n*m/2) cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(m==1){
                if(k) cout<<"NO"<<endl;
                else cout<<"YES"<<endl;
            }
            else{
                if(m%2){
                    if(k%2||k*2>n*(m-1)) cout<<"NO"<<endl;
                    else cout<<"YES"<<endl;
                }
                else{
                    if(k*2<m||(k-m/2)%2) cout<<"NO"<<endl;
                    else cout<<"YES"<<endl;
                }
            }
        }
    }
    return 0;
}