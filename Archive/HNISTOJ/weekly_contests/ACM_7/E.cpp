#include<iostream>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
int n,data[100000],in[1000];

int main(){
    cin>>n;
    int tmp=0;
    for(int i=1;i<=n;i++){
        cin>>in[i];
        data[in[i]]++;
        if(in[i]>tmp) 
            tmp=in[i];
    }
    int maxx=0,mark=1;
    for(int i=1;i<=tmp;i++){
        if(data[i]>maxx){
            maxx=data[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(data[in[i]]==maxx){
            cout<<in[i];
            break;
        }
    }
    return 0;
}