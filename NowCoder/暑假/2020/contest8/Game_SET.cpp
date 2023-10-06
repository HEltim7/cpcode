#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
using ARR=array<int,4>;
constexpr int N=256;
vector<vector<string>> dict{
    vector{string("*"),string("one"),string("two"),string("three")},
    vector{string("*"),string("diamond"),string("squiggle"),string("oval")},
    vector{string("*"),string("solid"),string("striped"),string("open")},
    vector{string("*"),string("red"),string("green"),string("purple")}
};
vector<int> valid[N][N];

ARR get(int i) {
    ARR arr{};
    for(int j=0,t=i;j<4;j++) {
        arr[j]=t%4;
        t/=4;
    }
    return arr;
}

void init() {
    vector<int> num;
    array<ARR,3> arr;
    for(int i=0;i<N;i++) {
        arr[0]=get(i);
        for(int j=i+1;j<N;j++) {
            arr[1]=get(j);
            for(int k=0;k<N;k++) {
                if(i==k||j==k) continue;
                arr[2]=get(k);
                bool ok=true;
                for(int x=0;x<4;x++) {
                    int wild=0;
                    num.clear();
                    for(int y=0;y<3;y++) {
                        if(arr[y][x]==0) wild++;
                        else num.emplace_back(arr[y][x]);
                    }
                    sort(num.begin(),num.end());
                    num.erase(unique(num.begin(),num.end()),num.end());
                    if(num.size()==2&&!wild) {
                        ok=false;
                        break;
                    }
                }
                if(ok) {
                    valid[i][j].emplace_back(k);
                    valid[j][i].emplace_back(k);
                }
            }
        }
    }
}

void solve() {
    int n;
    cin>>n;

    vector<int> vec,idx(N);
    for(int i=1;i<=n;i++) {
        int id=0;
        string s;
        for(int j=0,pw=1;j<4;j++) {
            getline(cin,s,'[');
            getline(cin,s,']');
            int x=find(dict[j].begin(),dict[j].end(),s)-dict[j].begin();
            id+=x*pw;
            pw*=4;
        }
        idx[id]=i;
        vec.emplace_back(id);
    }

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            for(int x:valid[vec[i]][vec[j]]) {
                if(idx[x]) {
                    cout<<idx[vec[i]]<<' '<<idx[vec[j]]<<' '<<idx[x]<<endl;
                    return;
                }
            }
        }
    }
    cout<<-1<<endl;
}

int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}