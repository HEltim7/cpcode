#include<iostream>
using namespace std;
const int N=1e4+10;
int bottle[N];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,step=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>bottle[i];
    }
    for(int j=1;j<=n;j++){
        for(int i=1;i<=n;i++){
            if(bottle[i]!=i){
                swap(bottle[i],bottle[bottle[i]]);
                step++;
            }
        }
    }
    cout<<step;
    return 0;
}