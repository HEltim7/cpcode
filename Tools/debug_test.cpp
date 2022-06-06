#include<set>
#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<tuple>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<array>
using namespace std;

#define __DEBUG
#ifdef __DEBUG
#include"debug_dev.hpp"
#else
#define debug(...)
#endif

int sum(int a,int b){
    return a+b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int arr[]={3,2,1};

    set<int> st{1,2,3};

    debug(arr);

    vector<pair<int,int>> vii;
    vii.emplace_back(1,1);
    vii.emplace_back(2,2);
    vii.emplace_back(7,77);
    debug(vii);

    vector<tuple<int,int,int>> viii;
    viii.emplace_back(1,2,3);
    viii.emplace_back(4,5,6);
    viii.emplace_back(7,8,9);
    debug(viii);

    tuple<int,int,char> tup={1,1,'#'};
    debug(tup);

    tuple<vector<int>> tv={vector(3,1)};
    debug(tv);

    debug(1,2,"asdf",vii);
    debug(arr,0,2,vii);
    int a=1,b=2,c=3;
    debug(a,b,c,arr); 

    vector<int> lv(110,7);
    debug(lv,1,105,lv);

    debug(st);
    for(int i=1;i<=100;i++) st.insert(i+100);
    debug(st);

    unordered_set<int> ust;
    for(int i=100;i<=300;i++) ust.insert(i);
    debug(ust);

    map<int,string> mp;
    for(int i=1;i<=200;i++) mp.emplace(i,"###");
    debug(mp);

    unordered_map<int,
        set<
            vector<
                tuple<
                    char,
                    pair<
                        bool,
                        string
                    >,
                    double
                >
            >
        >
    > namo;

    vector<tuple<char,pair<bool,string>,double>> vec;
    vec.push_back(make_tuple('A',make_pair(true,"str1"),1.7));
    set<vector<tuple<char,pair<bool,string>,double>>> tmpst;
    tmpst.insert(vec);
    namo.emplace(1,tmpst);

    debug(namo);

    // debug(namo,mp,ust,st,vii,viii,tv,tup,a,b,c);
    //debug(u,"->",v);

    int longarr[1000];
    debug(longarr,300,500);

    vector<char> longvec(1000,'A');
    debug(longvec,200,700);

    debug("--,--");
    debug(1,"---,---");

    debug(sum(1,2));
    debug(pair<int,int>(7,77));
    debug(max({1,2,3}));
    debug(',');

    multiset<int> mst;
    for(int i=1;i<=200;i++) mst.insert(i);
    multimap<int,deque<int>> mid;
    for(int i=1;i<=200;i++) {
        deque<int> dq(3,7);
        mid.emplace(i*i,dq);
    }

    debug(mst);
    debug(mid);

    queue<pair<int,int>> q;
    for(int i=1;i<=200;i++) q.emplace(i,i*2);
    debug(q);
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=10;i++) pq.emplace(i);
    debug(pq);
    debug(pq);

    // write("fastIO\n");
    // array<int,10> array1;
    // debug(array1);

    return 0;
}