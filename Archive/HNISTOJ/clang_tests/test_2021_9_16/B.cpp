#include <iostream>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string str;
    cin>>str;
    int left=0,ans=0,res=0;
    for(auto i:str){
        if(i=='(') left++;
        else if(i==')'){
            if(left) ans++;
            left=max(0,left-1);
        }
    }
    left=0;
    for(auto i:str){
        if(i=='{') left++;
        else if(i=='}'){
            if(left) res++;
            left=max(0,left-1);
        }
    }
    cout<<max(ans,res);
}