#include<iostream>
#include<vector>
using namespace std;

vector<int> div(vector<int> &A,int b,int &r){
    vector<int> C;
    for(int i=0;i<A.size();i++){
        r=r*10+A[i];
        C.push_back(r/b);
        r%=b;
    }
    return C;
}

int main(){
    string a;
    int b;
    cin>>a>>b;
    vector<int> A;
    for(int i=0;i<a.size();i++) A.push_back(a[i]-'0');
    int r=0;
    auto C=div(A,b,r);
    int i=0;
    while(C[i]==0&&i<C.size()-1) i++;
    for(;i<C.size();i++) cout<<C[i];
    cout<<'\n'<<r;
    return 0;
}