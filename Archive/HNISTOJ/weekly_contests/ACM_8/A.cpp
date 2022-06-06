#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int num;
    while(cin>>num&&num!=EOF){
        string data[num+1],tmp;
        for(int i=1;i<=num;i++){
            cin>>data[i];
        }
        int aim;
        cin>>aim;
        for(int i=1;i<=aim;i++){
            cin>>tmp;
            for(int j=1;j<=num;j++){
                if(data[j]==tmp){
                    cout<<"YES"<<endl;
                    break;
                }
                if(j==num)cout<<"NO"<<endl;
            }
        }
    }
    return 0;
}