#include<iostream>
using namespace std;
const int N=1e6+10;
int n,num[N],idx,k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int cnt=k;
        while(cnt){
            ++idx;
            if(idx>n) idx=1;
            if(num[idx]!=-1) cnt--;
        }
        num[idx]=-1;
        if(i==n) cout<<idx;
    }
    return 0;
}


/*

N=10;
K=7;
ans:
7 4 2 1 3 6 10 5 8 9

1 3
*/