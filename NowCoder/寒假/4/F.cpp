#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
int ch[1<<7];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ch['C']=1;
    ch['D']=2;
    ch['E']=3;
    ch['F']=4;
    ch['G']=5;
    ch['A']=6;
    ch['B']=7;
    string s;
    cin>>s;
    
    int pre=0;
    for(auto x:s){
        if(x=='<') pre--;
        else if(x=='>') pre++;
        else {
            cout<<ch[x];
            for(int i=1;i<=pre;i++) cout<<'*';
            for(int i=-1;i>=pre;i--) cout<<'.';
        }
    }
    return 0;
}