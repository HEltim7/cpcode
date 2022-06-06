#include<iostream>
#include<fstream>
using namespace std;

#define endl '\n'
const int N=1e3+10;
string str[N];

int main() {
    int t,n,m,k;
    ifstream in("E.in");
    ifstream out("E.out");
    ofstream judge("E.judge");

    in>>t;
    for(int z=1;z<=t;z++){
        string phone,res;
        in>>n>>m;
        for(int i=1;i<=n;i++) in>>str[i];
        in>>phone;

        out>>k;
        if(k==-1) continue;
        for(int i=1;i<=k;i++){
            int l,r,id;
            out>>l>>r>>id;
            while(l<=r) res+=str[id][l-1],l++;
        }
        if(phone==res) judge<<"test case ["<<z<<"]:OK"<<endl;
        else judge<<"test case ["<<z<<"]:WA"<<endl;
        // judge<<"=========="<<endl;
        judge<<"test data:"<<endl;
        judge<<n<<' '<<m<<endl;
        for(int j=1;j<=n;j++) judge<<str[j]<<endl;
        judge<<phone<<endl;
        judge<<"answer:"<<endl;
        judge<<res<<endl;
        judge<<"=========="<<endl;
        
    }
}