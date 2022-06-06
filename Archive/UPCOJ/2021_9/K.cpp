#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

typedef long long ll;
vector<int> n;
const ll maxx=2155000000;

vector<int> mul(vector<int> A,ll b){
    vector<int> C,D;
    ll r=0;
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
    while(D[D.size()-1]==0&&D.size()>1) D.pop_back();
    reverse(D.begin(),D.end());
    return D;
}

char check(ll var){
    vector<int> V,res;
    ll tmp=var;
    while(var){
        V.push_back(var%10);
        var/=10;
    }
    res=mul(V,tmp);
    if(res.size()>n.size()) return '>';
    else if(res.size()<n.size()) return '<';
    else if(res>n) return '>';
    else if(res<n) return '<';
    return '=';
}

int main(){
    string in,inn;
    cin>>in;
    for(int i=0;i<in.size();i++) n.push_back(in[i]-'0');
    ll mid=maxx/2;
    for(ll l=1,r=maxx;l<=r;mid=(l+r)/2){
        char ans=check(mid);
        if(ans=='<') l=mid+1;
        else if(ans=='>') r=mid-1;
        else {
            cout<<mid;
            return 0;
        }
    }
    
    if(check(mid+1)=='>'&&check(mid)=='<'){
        cout<<mid;
        return 0;
    }
    if(check(mid)=='>'&&check(mid)=='<'){
        cout<<mid-1;
        return 0;
    }
    return 0;
}