#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int arr[N],two[N];
bool isneg[N];

// #define __LOCAL
#ifdef __LOCAL
#include<debug>
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        memset(isneg,0,sizeof (bool)*(n+2));
        memset(two,0,sizeof (int)*(n+2));
        vector<int> zero;
        zero.push_back(0);
        for(int i=1;i<=n;i++) {
            cin>>arr[i];
            isneg[i]=isneg[i-1];
            two[i]=two[i-1];
            if(arr[i]<0) isneg[i]^=1;
            if(arr[i]==0) isneg[i]=0,zero.push_back(i);
            if(abs(arr[i])==2) two[i]++;
        }
        zero.push_back(n+1);
        
        int l=n,r=0,maxx=0;
        for(int i=1;i<zero.size();i++){
            int R=zero[i]-1;
            int L=zero[i-1]+1;
            if(isneg[R]==isneg[L-1]){
                debug("qwq");
                int cnt=two[R]-two[L-1];
                if(cnt>maxx) maxx=cnt,l=L-1,r=n-R;
            }
            else{
                int cnt=two[R]-two[L-1];
                debug(cnt);
                for(int j=L;j<=R;j++){
                    if(abs(arr[j])==2) cnt--;
                    if(arr[j]<0){
                        if(cnt>maxx)
                            maxx=cnt,l=j,r=n-R;
                        break;
                    }
                }
                cnt=two[R]-two[L-1];
                for(int j=R;j>=L;j--){
                    debug("qwq");
                    if(abs(arr[j])==2) cnt--;
                    if(arr[j]<0){
                        if(cnt>maxx)
                            maxx=cnt,l=L-1,r=n-j+1;
                        break;
                    }
                }
            }
        }

        cout<<l<<' '<<r<<endl;
    }
    return 0;
}