#include<iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int N=3e5+10;
LL num[N],s[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>s[i];
    LL res[3]={0};
    for(int i=1;i<n;i++){
        int j=i+2;
        int k=j%3;
        num[j]=num[j-3]+s[i]-s[i-1];
        if(num[j]<0) res[k]=max(res[k],-num[j]);
    }
    if(res[0]+res[1]+res[2]>s[0]) cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        num[0]=res[0];
        num[1]=res[1];
        num[2]=max(res[2],s[0]-res[0]-res[1]);
        for(int i=3;i<n+2;i++) num[i]+=num[i%3];
        for(int i=0;i<n+2;i++) cout<<num[i]<<' ';
    }
    return 0;
}