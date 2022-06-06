#include<iostream>
#include<stack>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef pair<int,int> PII;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    stack<PII> stk;
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        if(stk.empty()||stk.top().first!=in) stk.push({in,1}),cnt++;
        else if(stk.top().second+1==stk.top().first) cnt-=stk.top().second,stk.pop();
        else stk.top().second++,cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}