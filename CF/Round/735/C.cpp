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
        int n,m;
        cin>>n>>m;
        int res=n^m;
        res++;
        int level=0;
        while((1<<level)<=n&&((1<<level)&n)) level++;
        for(int i=level;i>=0;i--){
            int tmp=1<<i;
            if((res&tmp)&&(tmp&n)&&!(tmp&m)){
                res>>=(i+1);
                res<<=(i+1);
                break;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}