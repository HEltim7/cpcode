#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=1e3+10;
int ans[N+10];

void init(){
    int cnt=0;
    for(int i=1;cnt<N;i++){
        if(i%10!=3&&i%3!=0) ans[++cnt]=i;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    init();
    while(t--){
        int k;
        cin>>k;
        cout<<ans[k]<<endl;
    }
    return 0;
}