#include<iostream>
using namespace std;

#define endl '\n'
const int N=1e5+10;
string str=" ";
string make;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int k;
    cin>>k;
    char idx='a';

    while(str.length()<N){
        make+=idx;
        if(idx=='z') idx='a';
        else idx++;
        str+=make;
    }

    while(k--){
        int q;
        cin>>q;
        cout<<str[q]<<endl;
    }
    return 0;
}