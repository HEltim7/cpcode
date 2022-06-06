#include<iostream>
using namespace std;
const int N=1e3+10;
int line[N],ans[N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>line[i];
        ans[i]=1;
        for(int j=1;j<i;j++){
            if(line[i]>line[j]){
                ans[i]=max(ans[i],ans[j]+1);
            }
        }
    }
    int maxx=0;
    for(int i=1;i<=n;i++) maxx=max(ans[i],maxx);
    cout<<maxx;
    return 0;
}