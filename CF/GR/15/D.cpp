#pragma optimize(2)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=20;
int num[N];
int arr[N];
int n;
bool flag;

bool check(){
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
            if(abs(arr[j]-arr[i])==num[n]){
                flag=1;
                break;
            }
    return flag;
}

bool dfs(int deep){
    if(flag) return flag;
    if(deep>n) return check();
    for(int i=1;i<=deep;i++){
        arr[deep+1]=arr[i]+num[deep];
        dfs(deep+1);
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        flag=0;
        for(int i=1;i<=n;i++) cin>>num[i],num[i]=abs(num[i]);
        sort(num+1,num+1+n);
        for(int i=2;i<=n;i++) if(num[i]==num[i-1]) flag=1;
        if(flag){
            cout<<"YES"<<endl;
            continue;
        }
        arr[1]=0,arr[2]=num[1];
        dfs(2);
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
        cout<<"[debug] ARR:"<<' ';
        for(int i=1;i<=n;i++) cout<<arr[i]<<' ';
        cout<<endl;
    }
    return 0;
}