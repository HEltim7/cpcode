#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N=110;

void fn(int n){
    vector<int> num;
    int res=0;
    for(int i=1;i<=n/i;i++) if(n%i==0) num.push_back(i),num.push_back(n/i);
    num.erase(unique(num.begin(),num.end()),num.end());
    sort(num.begin(),num.end());
    for(auto x:num) cout<<x<<' ';
    cout<<'\n';
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int num;
        cin>>num;
        fn(num);
    }
    return 0;
}