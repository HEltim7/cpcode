#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=3e3+10;
int arr[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        LL ans=0;
        cin>>n;
        char ch;
        for(int i=1;i<=n;i++)
            cin>>ch,arr[i]=(ch=='+'?1:0);
        for(int i=1;i<n;i++){
            int plus=0,minus1=0,minus2=0;
            bool last=0;
            for(int j=i;j<=n;j++){
                if(arr[j]) plus++,last=0;
                else {
                    if(last) minus1--,minus2+=2,last=0;
                    else last=1,minus1++;
                }
                
                int dif=plus-minus1;
                int aim=dif;
                if(dif>=0&&dif<=minus2||dif<=0&&-dif<=minus2/2)
                    if((aim-minus2)%3==0) ans++;
                
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}