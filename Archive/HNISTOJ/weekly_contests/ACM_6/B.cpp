#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll data[10000000];


int main(){
    ll n,k=0,in;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>in;
        bool flag=0;
        for(int j=0;j<k;j++){
            if(in==data[j]){
                flag=1;
                break;
            }
        }
        if(!flag){
            data[k++]=in;
        }
    }
    for(int i=0;i<k;i++){
        cout<<data[i]<<endl;
    }
    return 0;
}