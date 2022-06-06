#include<vector>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    deque<pair<int,int>> q;
    int Q;
    cin>>Q;
    while(Q--){
        int op;
        cin>>op;
        if(op==1){
            int x,c;
            cin>>x>>c;
            q.push_back({c,x});
        }
        else{
            int c;
            cin>>c;
            LL sum=0;
            while(c){
                auto [cnt,x]=q.front();
                q.pop_front();
                if(c>=cnt){
                    c-=cnt;
                    sum+=1LL*cnt*x;
                }
                else{
                    sum+=1LL*c*x;
                    cnt-=c;
                    c=0;
                    q.push_front({cnt,x});
                }
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}