#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int num;
    while (cin>>num){
        for(int i=num+1;;i++){
            string s;
            int n=i;
            while (n){
                s+=n%10+'0';
                n/=10;
            }
            string t=s;
            reverse(s.begin(),s.end());
            if(s==t){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}