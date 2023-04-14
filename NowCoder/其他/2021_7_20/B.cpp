#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

struct carddata
{
    int data;
    char name;
} card[110];

bool cmp(carddata a,carddata b){
    return a.data<b.data;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    int idx=0;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        for(int j=1;j<=num;j++) cin>>card[++idx].data,card[idx].name=(char)(i-1+'A');
    }
    sort(card+1,card+idx+1,cmp);
    for(int i=1;i<=idx;i++) cout<<card[i].name;
    return 0;
}