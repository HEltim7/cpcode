#include<iostream>
using namespace std;

#define endl '\n'
const int N=1e5+10;
int row[N],col[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int x,y,t;
    cin>>x>>y>>t;
    for(int i=1;i<=t;i++){
        int a,b;
        cin>>a>>b;
        if(a==1) row[b]=i;
        else col[b]=i;
    }
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++)
            cout<<max(row[i],col[j])<<' ';
        cout<<endl;
    }
    return 0;
}