#include <iostream>
#include <queue>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int p;
    cin>>p;
    while (p--){
        int n;
        cin>>n;
        cout<<n<<' ';
        cin>>n;
        cout<<(n + 1) / 2<<endl;

        priority_queue<int> down;
        priority_queue<int, vector<int>, greater<int>> up;

        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int in;
            cin>>in;
            if (down.empty() || in <= down.top()) down.push(in);
            else up.push(in);
            if (down.size() > up.size() + 1) up.push(down.top()), down.pop();
            else if (up.size() > down.size()) down.push(up.top()), up.pop();
            if(i % 2 == 1) cout<<down.top()<<' ', cnt++;
            if(cnt==10) cout<<endl, cnt=0;
        }
        if(cnt != 0) cout<<endl;
    }
}