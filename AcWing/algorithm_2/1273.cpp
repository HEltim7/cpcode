#include <iostream>
#include <cmath>
using namespace std;

#define endl '\n'
const int N = 4e5+10;
const int M = 18;
int num[N];
int st[N][M];
int n;

void init(){
    for(int i = 0; i < M; i++)
        for(int j = 1; j <= n; j++)
            if(i == 0) st[j][i] = num[j];
            else st[j][i] = max(st[j][i-1], st[j + (1<<i-1)][i-1]);
}

int query(int l, int r){
    int len = r - l + 1;
    int k = log2(len);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>num[i];
    init();
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<query(l, r)<<endl;
    }
    return 0;
}