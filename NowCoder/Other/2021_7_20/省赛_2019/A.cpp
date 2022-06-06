#include<iostream>
using namespace std;

#define endl '\n'
#define check(col) (col>=l&&col<=r)
int l,r;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    while(cin>>n>>m){
        bool flag=0;
        bool res=1;
        bool end=0;
        int cnt=0;
        string str;
        for(int i=1;i<=n;i++){
            cin>>str;
            str=' '+str;
            for(int j=1;j<=m;j++){
                int in=str[j]-'0';
                cnt+=in;
                if(flag==0&&in==1){
                    //read 1 start
                    l=j;
                    r=j;
                    flag=1;
                    for(int k=j+1;k<=m;k++){
                        in=str[k]-'0';
                        if(in) r=k;
                        else break;
                    }
                    break;
                }
                else if(flag==1){
                    if(j==l&&in==0){
                        end=1;
                        continue;
                    }
                    if(end==1){
                        if(in==1) res=0;
                    }
                    else{
                        if(check(j)&&in==0||!check(j)&&in==1) res=0;
                    }

                }
            }
        }
        if(res&&cnt!=0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
/*
5 5
00000
00000
00000
00000
00001
5 5
00000
00000
00000
10000
11111
5 5
00000
00000
00000
00000
00000
5 5
00000
00000
00000
11111
00000
5 5
00000
00000
00110
00110
00001
5 5
00000
00000
00110
00110
00100
5 5
00000
00000
00100
00110
00110
5 5
00000
00000
00110
00110
00110
5 5
00000
00000
00100
00100
00100
5 5
00000
00000
00100
00000
00000
5 5
11111
11111
11111
11111
11111
1 1
0
1 1
1
1 2
1 0
1 2
1 0
*/