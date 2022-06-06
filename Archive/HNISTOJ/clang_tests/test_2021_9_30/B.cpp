#include<iostream>
#include<queue>
using namespace std;

int main(){
    int n,ans=0;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        q.emplace(in);
    }
    for(int i=1;i<n;i++){
        int a=q.top();
        q.pop();
        int b=q.top();
        q.pop();
        q.emplace(a+b);
        ans+=a+b;
    }
    cout<<ans;
    return 0;
}