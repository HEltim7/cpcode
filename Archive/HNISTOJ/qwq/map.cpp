#include<iostream>
#include<map>
#include<vector>
#define PB push_back
using namespace std;
const int N=1e3;
typedef pair <vector<int>,string> PVS;
typedef map<int,PVS>::value_type mapval;
map <int,PVS> amap;

int main(){
    PVS data1;
    data1.first.reserve(N);
    data1.first.PB(1);
    data1.second.PB('x');
    amap.emplace(0,data1);
    map<int,PVS>::iterator iter=amap.begin();
    cout<<iter->first<<' ';
    cout<<iter->second.first[0]<<' ';
    cout<<iter->second.second<<' ';
    amap.clear();
    if(amap.empty()) cout<<"isempty"<<endl;
    mapval data2;
    data2.second.first.reserve(N);
    // data2.first=123;
    //can't modify the key of map
    data2.second.first[0]=23333;
    data2.second.second.PB('#');
    cout<<data2.second.first.front()<<' ';
    cout<<data2.second.second<<endl;
    amap.insert(data2);
    iter=amap.find(0);
    cout<<iter->second.second;
    return 0;
}