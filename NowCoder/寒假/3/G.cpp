#include<iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;
const int N=1e3+10;
int ind[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        if(l) ind[i]++,ind[l]++;
        if(r) ind[i]++,ind[r]++;
    }
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        if(l) ind[i]--,ind[l]--;
        if(r) ind[i]--,ind[r]--;
    }

    for(int i=1;i<=n;i++) debug(i),debug(ind[i]);

    for(int i=1;i<=n;i++) 
        if(ind[i]<0){
            cout<<1<<endl<<i;
            return 0;
        }
    cout<<0;
    return 0;
}