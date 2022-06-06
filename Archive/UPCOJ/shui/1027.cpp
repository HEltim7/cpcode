#include<bits/stdc++.h>
using namespace std;

#define endl '\n';

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);
    int day;
    cin>>day;
    for(int i=1000;i>=0;i--){
        if(i*i+i*4<=day){
            cout<<i;
            return 0;
        }
    }
    return 0;
}