#include<bits/stdc++.h>
using namespace std;

#define endl '\n';

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    int apple;
    int cnt=0;
    int level[5]={0};
    while(cin>>apple&&apple>=20){
        if(apple>=70) level[1]++;
        else if(apple>=60) level[2]++;
        else if(apple>=50) level[3]++;
        else level[4]++;
        cnt++;
    }
    cout<<cnt<<endl;
    for(int i=1;i<=4;i++) cout<<level[i]<<' ';
    return 0;
}