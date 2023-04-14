#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
vector<int> res;

inline bool check(int x){
    for(int i=2;i<=x/i;i++) if(x%i==0) return 0;
    return 1;
}

void init(){
    LL num=2;
    int idx=3;
    while(num<=1e9){
        res.push_back(num);
        for(int i=idx;i<=1e9;i++)
            if(check(i)){
                num*=i;
                idx=i+1;
                break;
            }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    init();
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<-1<<endl;
            continue;
        }
        for(int i=res.size()-1;i>=0;i--){
            auto num=res[i];
            if(num<=n){
                cout<<num<<' ';
                break;
            }
        }
        for(int i=n;i>=2;i--) 
            if(check(i)){
                cout<<i<<endl;
                break;
            }
    }
    return 0;
}