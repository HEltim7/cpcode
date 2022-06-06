#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        string in;
        cin>>in;
        int a=0,b=0;
        in.push_back('0');
        bool ans=1;
        for(auto x:in){
            if(a&&x!='a') {
                if(a<=1) ans=0;
                a=0;
            }
            else if(b&&x!='b'){
                if(b<=1) ans=0;
                b=0;
            }
            if(x=='a') a++;
            else b++;
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}