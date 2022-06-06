#include<iostream>
using namespace std;

#define lowbit(x) x&-x

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        int num,res=0;
        cin>>num;
        while(num){
            num-=lowbit(num);
            res++;
        }
        cout<<res<<' ';
    }
    return 0;
}