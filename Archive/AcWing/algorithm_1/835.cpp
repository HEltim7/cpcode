#include<iostream>
using namespace std;

const int N=1e5+10;
struct node{
    char c;
    int num;
    int nex[26];
} trie[N]; //trie[0] is head node
int idx;

void insert(string in){
    int loc=0;
    for(int i=0;i<in.size();i++){
        int tmp=in[i]-'a';
        if(trie[loc].nex[tmp]==0){
            // build new node
            trie[loc].nex[tmp]=++idx;
        }
        loc=trie[loc].nex[tmp];
    }
    trie[loc].num++;
}

void query(string in){
    int loc=0;
    for(int i=0;i<in.size();i++){
        int tmp=in[i]-'a';
        loc=trie[loc].nex[tmp];
        if(loc==0){
            cout<<0<<'\n';
            return ;
        }
    }
    cout<<trie[loc].num<<'\n';
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int n;
    cin>>n;
    string op,in;
    for(int i=1;i<=n;i++){
        cin>>op>>in;
        if(op=="I") insert(in);
        else query(in);
    }
    return 0;
}