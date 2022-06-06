#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'
using LL=long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<string> name;
    multiset<string> cnt;
    for(int i=1;i<=2*n;i++){
        string in;
        cin>>in;
        name.push_back(in);
        cnt.insert(in);
    }

    for(int i=0;i<name.size();i+=2){
        if(name[i]==name[i+1]){
            if(cnt.count(name[i])>2){
                cout<<"No";
                return 0;
            }
        }
        else if(cnt.count(name[i])>1&&cnt.count(name[i+1])>1){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}