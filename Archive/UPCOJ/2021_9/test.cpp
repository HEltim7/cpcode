#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;

typedef long long ll;
vector<int> n;
const ll maxx=2155000000;

vector<int> mul(vector<int> A,int b){
    vector<int> C,D;
    int r=0;
    for(int i=0;i<A.size();i++){
        C.push_back((A[i]*b+r)%10);
        r=(A[i]*b+r)/10;
    }
    while(r){
        C.push_back(r%10);
        r/=10;
    }
    A=C;
    for(int i=0;i<A.size();i++){
        D.push_back((A[i]*b+r)%10);
        r=(A[i]*b+r)/10;
    }
    while(r){
        D.push_back(r%10);
        r/=10;
    }
    reverse(D.begin(),D.end());
    return D;
}


int main(){
    string in;
    cin>>in;
    for(int i=0;i<in.size();i++) n.push_back(in[i]-'0');
    reverse(n.begin(),n.end());
    vector<int>C=mul(n,100);
    for(int i=0;i<C.size();i++) cout<<C[i];
    return 0;
}