#include<bits/stdc++.h>
using namespace std;

#define endl '\n';
string a="IUJTMFHXOKBQEAPZCDWRYNVSGL";
string b="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char biao[1000];

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0),std::cout.tie(0);

    for(int i=0;i<a.size();i++) biao[a[i]]=b[i];

    string s;
    int n;
    cin>>n;
    while(n--){
        cin>>s;
        for(auto i:s) cout<<biao[i];
        cout<<endl;
    }
    return 0;
}