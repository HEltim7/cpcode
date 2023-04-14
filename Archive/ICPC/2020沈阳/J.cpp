#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
int arr[10],brr[10];
int num[10];

inline int cal(){
    int dif[10]={0};
    dif[0]=num[0];
    for(int i=1;i<4;i++) dif[i]=num[i]-num[i-1];
    int res=0;
    int fu=0;
    int ze=0;
    for(int i=0;i<4;i++)
    {
        if(dif[i]<0) fu+=-dif[i];
        else ze+=dif[i];
    }
    res=max(ze,fu);
    return res;
}

int main() {
    // freopen64("in.txt","r",stdin);
    // freopen64("out.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        string a,b;
        cin>>a>>b;
        int ans=1000;
        for(int i=0;i<4;i++) arr[i]=a[i]-'0';
        for(int i=0;i<4;i++) brr[i]=b[i]-'0';
        for(int i=0;i<=15;i++){
            int bak[5],cnt=0;
            for(int j=0;j<=3;j++){
                if(i&(1<<j)){
                    if(arr[j]>brr[j]) bak[j]=num[j]=10+(brr[j]-arr[j]);
                    else bak[j]=num[j]=brr[j]-arr[j];
                }
                else {
                    if(arr[j]>=brr[j]) bak[j]=num[j]=brr[j]-arr[j];
                    else bak[j]=num[j]=brr[j]-arr[j]-10;
                }
                if(bak[j]==0) cnt++;
            }
            ans=min(ans,cal());
            if(cnt==0) continue;
            for(int j=0;j<=80;j++){
                for(int z=0;z<=3;z++) num[z]=bak[z];
                int tmp[5];
                int tmpj=j;
                tmp[3]=tmpj%3,tmpj/=3;
                tmp[2]=tmpj%3,tmpj/=3;
                tmp[1]=tmpj%3,tmpj/=3;
                tmp[0]=tmpj%3,tmpj/=3;
                for(int k=0;k<=3;k++){
                    if(bak[k]) continue;
                    if(tmp[k]==1) num[k]=10;
                    else if(tmp[k]==2) num[k]=-10;
                    else if(tmp[k]==0) num[k]=0;
                }
                ans=min(ans,cal());
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}