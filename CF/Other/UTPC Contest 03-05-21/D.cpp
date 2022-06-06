#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;

int main(){
    int l,w,H,V;
    cin>>l>>w>>H>>V;
    int h[H+2],v[V+2];
    h[0]=0,v[0]=0;
    h[H+1]=l,v[V+1]=w;
    for(int i=1;i<=H;i++) cin>>h[i];
    for(int i=1;i<=V;i++) cin>>v[i];
    sort(v,v+V+2),sort(h,h+H+2);
    int markr=0,markc=0;
    ll maxx=0;
    for(int i=H+1;i>0;i--){
        for(int j=V+1;j>0;j--){
            if((h[i]-h[i-1])*(v[j]-v[j-1])>=maxx){
                maxx=(h[i]-h[i-1])*(v[j]-v[j-1]);
                markr=i;
                markc=j;
            }
        }
    }
    cout<<v[markc-1]<<' '<<h[markr-1]<<' '<<v[markc]<<' '<<h[markr];
    return 0;
}