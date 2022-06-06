#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e3+10;
int num[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int len;
        cin>>len;
        for(int i=1;i<=len;i++){
            cin>>num[i];
        }
        for(int i=1;i<=len;i++){
            if(num[i]!=i){
                int aim=0;
                for(int j=i+1;j<=len;j++){
                    if(num[j]==i){
                        aim=j;
                        break;
                    }
                }
                for(int j=1;j<i;j++) cout<<num[j]<<' ';
                for(int j=aim;j>=i;j--) cout<<num[j]<<' ';
                for(int j=aim+1;j<=len;j++) cout<<num[j]<<' ';
                cout<<endl;
                break;
            }
            if(i==len){
                for(int j=1;j<=len;j++) cout<<num[j]<<' ';
                cout<<endl;
            }
        }
    }
    return 0;
}