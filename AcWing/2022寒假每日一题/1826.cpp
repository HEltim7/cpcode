#include<iostream>
#include<cassert>
using namespace std;

#define endl '\n'
#define debug(x) cout << "[debug] " #x << " = " << x << endl
typedef long long LL;

const int N=1e5+10,INF=40000*40000;
int maxx1[4];//上下左右的最大值
int maxx2[4];//上下左右的次大值
int id[4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int row,col;
        cin>>row>>col;
        if(i==1){
            maxx1[0]=maxx1[1]=row;
            maxx1[2]=maxx1[3]=col;
            id[0]=id[1]=id[2]=id[3]=1;
        }
        else if(i==2){
            maxx2[0]=maxx2[1]=row;
            maxx2[2]=maxx2[3]=col;
            if(maxx1[0]<maxx2[0]) swap(maxx1[0],maxx2[0]),id[0]=2;
            if(maxx1[1]>maxx2[1]) swap(maxx1[1],maxx2[1]),id[1]=2;
            if(maxx1[2]>maxx2[2]) swap(maxx1[2],maxx2[2]),id[2]=2;
            if(maxx1[3]<maxx2[3]) swap(maxx1[3],maxx2[3]),id[3]=2;
        }
        else{
            if(row>=maxx1[0]) maxx2[0]=maxx1[0],maxx1[0]=row,id[0]=i;
            else if(row>maxx2[0]) maxx2[0]=row;

            if(row<=maxx1[1]) maxx2[1]=maxx1[1],maxx1[1]=row,id[1]=i;
            else if(row<maxx2[1]) maxx2[1]=row;

            if(col<=maxx1[2]) maxx2[2]=maxx1[2],maxx1[2]=col,id[2]=i;
            else if(col<maxx2[2]) maxx2[2]=col;

            if(col>=maxx1[3]) maxx2[3]=maxx1[3],maxx1[3]=col,id[3]=i;
            else if(col>maxx2[3]) maxx2[3]=col;
        }
    }

    int ans=INF;
    for(int i=0;i<4;i++){
        int edge[4];
        for(int j=0;j<4;j++) edge[j]=maxx1[j];
        for(int j=0;j<4;j++) if(id[j]==id[i]) edge[j]=maxx2[j];
        ans=min(ans,(edge[0]-edge[1])*(edge[3]-edge[2]));
    }
    cout<<ans;
    return 0;
}