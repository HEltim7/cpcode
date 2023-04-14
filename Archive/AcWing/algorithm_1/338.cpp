#include <iostream>
#include <cstring>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

typedef long long ll;

ll sum[11];

ll count(int num){
    for(int i=0;i<=9;i++){
        int tmp=num;
        int cnt=1;
        while(tmp){
            if(i) sum[i]+=num/(cnt*10)*cnt; //+abc*10..0
            else sum[0]+=(num/(cnt*10)-1)*cnt;
            if(tmp%10>i) sum[i]+=cnt; //+10..0
            else if(tmp%10==i) sum[i]+=num%cnt+1; //efg+1
            tmp/=10;
            cnt*=10;
        }
    }

    ll res=0;
    for(int i=0;i<=9;i++) res+=sum[i];
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a,b;
    while(cin>>a>>b &&a &&b){
        if(a>b) swap(a,b);
        memset(sum,0,sizeof sum);
        count(a-1);
        for(int i=0;i<=9;i++) sum[i]=-sum[i];
        count(b);
        for(int i=0;i<=9;i++) cout<<sum[i]<<' ';
        cout<<endl;
    }
    return 0;
}