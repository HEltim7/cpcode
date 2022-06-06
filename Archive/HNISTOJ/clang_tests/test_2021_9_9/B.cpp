#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> v;

void selection_sort(int idx){
    int minn=idx;
    for(int i=idx;i<n;i++) if(v[i]<v[minn]) minn=i;
    cout<<"swap(a["<<idx<<"],a["<<minn<<"]):";
    swap(v[idx],v[minn]);
    for(int i=0;i<n-1;i++) cout<<v[i]<<' ';
    cout<<v[n-1]<<endl;
    if(++idx<n) selection_sort(idx);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int in;
    cin>>n,in;
    for(int i=1;i<=n;i++) cin>>in,v.push_back(in);
    selection_sort(0);
}