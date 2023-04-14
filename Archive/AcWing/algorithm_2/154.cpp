#include<iostream>
using namespace std;

const int N=1e6+10;
int que[N];
int num[N];
int h=1,t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>num[i];
    for(int i=1;i<=n;i++){
        while(num[i]<=num[que[t]]&&h<=t) t--;
        que[++t]=i;
        if(que[h]+k<=i) h++;
        if(i>=k)cout<<num[que[h]]<<' ';
    }
    cout<<endl;

    h=1,t=0;
    for(int i=1;i<=n;i++){
        while(num[i]>=num[que[t]]&&h<=t) t--;
        que[++t]=i;
        if(que[h]+k<=i) h++;
        if(i>=k)cout<<num[que[h]]<<' ';
    }
    return 0;
}