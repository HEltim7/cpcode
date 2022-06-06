#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=50;
int num[N];
int backup[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int len;
        int res=0;
        char c;
        cin>>len;
        
        for(int i=1;i<=len;i++){
            cin>>c;
            num[i]=(int)(c-'a');
            backup[i]=num[i];
        }

        sort(num+1,num+1+len);
        for(int i=1;i<=len;i++) if(num[i]!=backup[i]) res++;
        cout<<res<<endl;
    }
    return 0;
}