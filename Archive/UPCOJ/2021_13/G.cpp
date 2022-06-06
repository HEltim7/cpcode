#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a,b;
    cin>>a;
    b=a;
    vector<int> A;
    while(a){
        A.push_back(a%10);
        a/=10;
    }
    cout<<"************************";
    for(auto x:A) cout<<"*";
    cout<<'\n';
    cout<<"*Welcome,ContestantNo."<<b<<"!*\n";
    cout<<"************************";
    for(auto x:A) cout<<"*";
    return 0;
}