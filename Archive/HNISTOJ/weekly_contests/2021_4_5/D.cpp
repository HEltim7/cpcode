#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e3+10;
const int M=1e6+10;
int n,cnt;
struct node
{
    int val;
    int same;
} num[N];

bool cmp(node a,node b){
    return a.val<b.val;
}

int main(){
    cin>>n;
    int in;
    bool isnew=1;
    while(n--){
        cin>>in;
        for(int i=0;i<cnt;i++){
            if(num[i].val==in){
                num[i].same++;
                isnew=0;
                break;
            }
        }
        if(isnew){
            num[cnt].val=in;
            num[cnt++].same=1;
        }
        isnew=1;
    }
    sort(num,num+cnt,cmp);
    for(int i=0;i<cnt;i++){
        cout<<num[i].val<<' '<<num[i].same<<endl;
    }
    return 0;
}