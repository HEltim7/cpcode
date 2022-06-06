#include<iostream>
using namespace std;
typedef unsigned long long ull;
const int N=1e5+10;
bool trie[30*N][2];
int num,idx;

void insert(int in){//每次存储最前一位
    int p=;
    while(in)
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        cin>>num;
        insert(num);
    }

    return 0;
}