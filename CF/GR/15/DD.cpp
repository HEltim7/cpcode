#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=20;
int num[N];
int arr[N];
int n;
bool flag;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        flag=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>num[i],num[i]=abs(num[i]);
        sort(num+1,num+1+n);
        if(n==1&&num[1]==0){
            cout<<"YES"<<endl;
            continue;
        }
        else if(n==1){
            cout<<"NO"<<endl;
            continue;
        }

        set<int> s;
        for(int i=1;i<=(1<<n)-1;i++){
            int res=0;
            for(int j=0;j<=n-1;j++){
                if(i& (1<<j)){
                    res+=num[j+1];
                }
            }
            if(s.find(res)==s.end()) 
                s.emplace(res);
            else{
                flag=1;
                break;
            }
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}