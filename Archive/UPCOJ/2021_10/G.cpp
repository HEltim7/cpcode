#include<iostream>
#include<vector>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    vector<int> base1,base2,in;
    for(int i=1;i<=5;i++) base1.push_back(i);
    for(int i=2;i<=6;i++) base2.push_back(i);
    while (n--){
        for(int i=1;i<=5;i++){
            int dice;
            cin>>dice;
            in.push_back(dice);
        }
        if(in==base1||in==base2) cout<<"Y"<<'\n';
        else cout<<"N"<<'\n';
        in.clear();
    }
    return 0;
}