#include<bits/stdc++.h>
using namespace std;
const long N=1e6;
long n,sum;
long a[N+10];
int main(){
    cin>>n;
    for(long i=1;i<=n;i++){
        scanf("%ld",&a[i]);
    }
    long start=1;
    for(long i=2;i<=n;i++){
        for(long j=start;j<i;j++){
            if(a[j]==a[i]){
                sum++;
                start=i;
                break;
            }
        }
    }
    cout<<sum;
    return 0;
}