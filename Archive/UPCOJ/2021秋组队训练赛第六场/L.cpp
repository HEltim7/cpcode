#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef vector<int> VI;
const int N=110;
int len[N];
VI ans;

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len[i];
        len[i]+=2;
    }
    int cnt=100;
    for(int i=1;i<=n;i++){
        ans.clear();
        int tmp=cnt++;
        int div=100;
        for(int j=0;j<len[i]-3;j++) ans.push_back(0);
        for(int j=1;j<=3;j++){
            ans.push_back(tmp%10);
            tmp/=10;
        }
        reverse(ans.begin(),ans.end());
        for(auto x:ans) cout<<x;
        cout<<' ';
    }
    return 0;
}

/*

1 2 3 4 5
> 1 2 3 4 5

5 4 3 2 1
100000 10000 1000 100 10

100 99 ... 2 1
111... 112... 113... 121... ... 211... 
100... 101... 102... 110... ... 120...


*/