#include<iostream>
using namespace std;

const int N=1e5+10;
int stack[N];
int tail;
int n,in;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>in;
        while(tail&&stack[tail]>=in) tail--;
        stack[++tail]=in;
        for(int j=tail;j>=1;j--){
            if(stack[j]<in){
                cout<<stack[j]<<' ';
                break;
            }
            if(j==1) cout<<-1<<' ';
        }
    }
    return 0;
}