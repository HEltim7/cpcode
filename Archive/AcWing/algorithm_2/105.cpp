#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5+10;
LL pfx[N], row[N], col[N], c[N];

LL swap(LL a[],int n){
    for(int i = 1; i <= n; i++) pfx[i] = pfx[i - 1] + a[i];
    LL avg, ans = 0;
    if(pfx[n] % n != 0) return -1;
    else avg = pfx[n] / n;
    for(int i = 1; i <= n; i++) c[i] = pfx[i - 1] - (i - 1) * avg;
    sort(c + 1, c + 1 + n);
    for(int i = 1; i <= n/2; i++) ans += abs(c[n-i+1] - c[i]);
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n, m, t;
    cin>>n>>m>>t;
    while (t--){
        int r, c;
        cin>>r>>c;
        row[r]++;
        col[c]++;
    }
    LL ansr = swap(row, n);
    LL ansc = swap(col, m);
    if(ansr == -1 && ansc == -1) cout<<"impossible";
    else if (ansc == -1) cout<<"row "<<ansr;
    else if (ansr == -1) cout<<"column "<<ansc;
    else cout<<"both "<<ansr + ansc;
    return 0;
}

/*

x1=x1;
x2=x1-(a1-avg)
x3=x2-(a2-avg) -> x3=x1-(a1-avg)-(a2-avg)=x1-(a1+a2)+2avg
x4=x3-(a3-avg) -> x4=x1-(a1+a2+a3)+3avg

xn=x1-(a1+...+an-1)+(n-1)avg

*/