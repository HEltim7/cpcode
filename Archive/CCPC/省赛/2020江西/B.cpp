#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

#define endl '\n'
vector<int> ans;

void getans(int a,int b){
    int tmp=a/b;
    ans.push_back(tmp);
    a-=tmp*b;
    if(a==1){
        ans.push_back(b);
        return;
    }
    getans(b,a);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T,x,y;
    cin>>T;
    while(T--){
        ans.clear();
        cin>>x>>y;
        if(x==1){
            cout<<1<<' '<<0<<' '<<y<<endl;
            continue;
        }
        getans(x,y);
        cout<<ans.size()-1<<' ';
        for(int x:ans) cout<<x<<' ';
        cout<<endl;
    }
    return 0;
}