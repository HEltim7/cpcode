//#include<iostream>
//#include<iomanip>
//#include<cstring>
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int n,m,start,endd;
bool data[110];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>start>>endd;
        for(int j=start;j<=endd;j++){
            data[j]=1;
        }
    }
    int sum=0;
    for(int i=1;i<=m;i++){
        if(data[i]){
            sum++;
        }
    }
    cout<<m-sum<<endl;
    if(sum<m){
        for(int k=1;k<=m;k++){
            if(!data[k]){
                cout<<k<<' ';
            }
        }
    }
    return 0;
}