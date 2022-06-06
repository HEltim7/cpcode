#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long l;

struct data{
    string id;
    l start;
    l end;
}man[25][1010];

l trans(string in){
    l time=0;
    time=(in[0]-'0')*36000+(in[1]-'0')*3600+(in[3]-'0')*600+(in[4]-'0')*60+(in[6]-'0')*10+in[7]-'0';
    return time;
}

int main(){
    int day,people;
    string startT,endT;
    cin>>day;
    for(int i=1;i<=day;i++){
        cin>>people;
        l maxx=0,minn=86400,markS=0,markE=0;
        for(int j=1;j<=people;j++){
            cin>>man[i][j].id;
            cin>>startT;
            man[i][j].start=trans(startT);
            cin>>endT;
            man[i][j].end=trans(endT);
            if(man[i][j].start<minn){
                markS=j;
                minn=man[i][j].start;
            }
            if(man[i][j].end>maxx){
                markE=j;
                maxx=man[i][j].end;
            }
        }
        cout<<man[i][markS].id<<' '<<man[i][markE].id<<endl;
    }
    return 0;
}