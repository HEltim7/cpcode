#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c;
    cin>>c;
    while(c--){
        int n;
        int sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int tmp;
            cin>>tmp;
            sum+=tmp;
        }
        if(sum>=n) cout<<sum-n<<endl;
        else cout<<1<<endl;
    }
    return 0;
}