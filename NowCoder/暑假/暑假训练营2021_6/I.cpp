#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

const int N=2010;
int n,m;
int cnt;

struct interval
{
    int l;
    int r;
} inter[N],merg[N];

bool cmp(interval a,interval b){
    return a.l<b.l;
}

void merge(){
    merg[1]=inter[1];
    for(int i=2;i<=m;i++){
        if(inter[i].l==merg[cnt].r+1) merg[cnt].r=inter[i].r;
        else merg[++cnt]=inter[i];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cnt=1;

        for(int i=1;i<=m;i++){
            cin>>inter[i].l>>inter[i].r;
            if(inter[i].l>inter[i].r) inter[i].r+=n;
        }
        sort(inter+1,inter+1+m,cmp);

        merge();
        for(int i=1;i<=cnt;i++){
            if(merg[i].r>n) merg[i].r-=n;
        }

        if(cnt==1){
            cout<<1<<endl;
            cout<<merg[1].l<<' '<<merg[1].r<<endl;
        }
        else{
            cout<<cnt<<endl;
            cout<< merg[1].l<<' '<<merg[cnt].r<<endl;
            for(int i=1;i<cnt;i++)
                cout<<merg[i+1].l<<' '<<merg[i].r<<endl;
        }
    }
    return 0;
}