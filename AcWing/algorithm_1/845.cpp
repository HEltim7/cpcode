#include<bits/stdc++.h>
using namespace std;

struct node{
    string s;
    int step;
    int row;
    int col;
} qe;

queue<node> q;
unordered_map<string,int> h;
unordered_map<string,int>::iterator iter;
string aim="12345678x";
int mr[4]={1,-1,0,0};
int mc[4]={0,0,1,-1};
int ans=-1;

bool check(node &qe){
    if(qe.row>2||qe.row<0||qe.col>2||qe.col<0) return 0;
    if(h.find(qe.s)!=h.end()) return 0;
    return ++qe.step;
}

void bfs(){
    if(q.empty()) return;
    qe=q.front();
    if(qe.s==aim){
        ans=qe.step;
        return;
    }
    for(int i=0;i<4;i++){
        qe.row+=mr[i],qe.col+=mc[i];
        swap(qe.s[qe.row*3+qe.col],qe.s[(qe.row-mr[i])*3+qe.col-mc[i]]);
        if(check(qe)){
            h.emplace(qe.s,qe.step);
            q.push(qe);
        }
        qe=q.front();
    }
    q.pop();
    bfs();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    char in;
    for(int i=0;i<9;i++) cin>>in,qe.s+=in;
    for(int i=0;i<qe.s.size();i++) if(qe.s[i]=='x') qe.row=i/3,qe.col=i%3;
    h.emplace(qe.s,qe.step);
    q.push(qe);
    bfs();
    cout<<ans;
    return 0;
}