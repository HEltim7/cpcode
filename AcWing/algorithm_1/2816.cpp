#include<iostream>
#include<unordered_map>
using namespace std;

const int N=1e5+10;
int a[N],b[N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1,j=1;i<=n&&j<=m;j++){
        if(a[i]==b[j]) i++;
        if(i==n+1){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
    return 0;
}