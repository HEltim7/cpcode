#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,sum=0;
    cin>>n;
    int maxx=0,minn=0;
    int maxans=0,minans=0;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        if(!in) sum++;
        else sum--;
        if(!in) maxx=max(maxx,sum),maxans=max(maxans,sum-minn);
        else minn=min(minn,sum),minans=min(minans,sum-maxx);
    }
    cout<<maxans-minans+1<<endl;
    return 0;
}