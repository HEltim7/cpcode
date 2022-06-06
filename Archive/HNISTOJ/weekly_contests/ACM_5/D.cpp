#include<bits/stdc++.h>
using namespace std;
int n;
typedef struct {
    int start;
    int end;
}tvdata;

bool cmp(tvdata a,tvdata b){
    return a.end<b.end;
}

int fn(){
    int next,time=0,maxtime=0,ans=0;
    tvdata tv[n+1]; 
    for(int i=1;i<=n;i++) {cin>>tv[i].start>>tv[i].end;if(tv[i].end>maxtime) maxtime=tv[i].end;}
    cin>>next;
    sort(tv,tv+n+1,cmp);
    for(int i=1;time<maxtime&&i<=n;i++){
        if(time<=tv[i].start){
            time=tv[i].end;
            ans++;
        }
    }
    cout<<ans<<endl;
    return next;
}

int main(){
    cin>>n;
    do
    {
        n=fn();
    } while (n!=0);
    return 0;
}