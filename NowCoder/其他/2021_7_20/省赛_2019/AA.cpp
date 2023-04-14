#include<iostream>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    string str[20];
    while(cin>>n>>m){
        int cnt=0;
        int ai=0,aj=0;
        int bi=0,bj=0;
        for(int i=0;i<n;i++){
            cin>>str[i];
            for(auto x:str[i]) if(x=='1') cnt++;
        }

        if(cnt==0){
            cout<<"No"<<endl;
            continue;
        }

        bool flag=1;
        for(int i=0;i<n&&flag;i++){
            for(int j=0;j<m&&flag;j++){
                if(str[i][j]=='1'){
                    ai=i;
                    aj=j;
                    flag=0;
                }
            }
        }
        flag=1;
        for(int i=n-1;i>=0&&flag;i--){
            for(int j=m-1;j>=0&&flag;j--){
                if(str[i][j]=='1'){
                    bi=i;
                    bj=j;
                    flag=0;
                }
            }
        }
        bool res=1;
        if((bi-ai+1)*(bj-aj+1)!=cnt) res=0;
        for(int i=ai;i<=bi;i++){
            for(int j=aj;j<=bj;j++){
                if(str[i][j]=='0') res=0;
            }
        }
        if(res) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}