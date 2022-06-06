#include<iostream>
#include<iomanip>
using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string in;
    while(getline(cin,in)){
        int res=0,cnt=0;
        for(char x:in){
            if(x>='A'&&x<='D'){
                cnt++;
                res+=4+'A'-x;
            }
            else if(x=='F') cnt++;
            else if(x!=' ') res=-1e9;
        }
        if(res<0) cout<<"Unknown"<<endl;
        else cout<<fixed<<setprecision(2)<<res*1./cnt<<endl;
    }
    return 0;
}