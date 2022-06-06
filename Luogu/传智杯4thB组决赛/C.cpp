#include<iostream>
#include<set>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e3+10;
int a[N],b[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        set<int> sta,stb;
        for(int i=1;i<=n;i++) cin>>a[i],sta.insert(a[i]);
        for(int i=1;i<=n;i++) cin>>b[i],stb.insert(b[i]);
        if(sta!=stb){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++){
            if(a[i]==b[i]) continue;
            for(int j=i+1;j<=n;j++){
                if(a[j]==b[i]){
                    for(int k=j;k>i;k--){
                        cout<<k<<' '<<k-1<<endl;
                        swap(a[k],a[k-1]);
                    }
                    break;
                }
            }
        }
        cout<<"0 0"<<endl;
    }
    return 0;
}