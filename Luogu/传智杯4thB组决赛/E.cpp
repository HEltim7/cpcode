#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e2+10;
int n,m,vol,now;
int weap1,weap2;
struct AMMO {
    int id,w,num,t;
};
vector<AMMO> pack;
int ammoid[]={-1,14,14,14,14,15,15,15,16,16};
int weight[]={0,0,0,0,0,0,0,0,0,0,50,40,30,20,2,1,5};

struct BLOCK {
    bool type;//0物质1敌人
    int a,b;
} tab[N][N];

inline bool need_ammo(int id){
    return ammoid[weap1]==id||ammoid[weap2]==id;
}

inline void get_lv(int x,int &res){
    if(x==0) res=0;
    else if(x==4) res=1;
    else if(x==3||x==6||x==7) res=2;
    else if(x==1||x==2||x==5) res=3;
    else res=4;
}

inline void update_weapon(int w){
    int lv1,lv2,curw;
    get_lv(weap1,lv1);
    get_lv(weap2,lv2);
    get_lv(w,curw);
    if(curw>lv1) weap1=w;
    else if(curw>lv2) weap2=w;
}

inline int del(int num){
    if(pack.size()==0) return 0;
    int maxi1=-1,maxi2=-1;
    for(int i=0;i<pack.size();i++){
        if(!need_ammo(pack[i].id)){
            if(maxi1==-1) maxi1=i;
            else if(pack[maxi1].t<pack[i].t) maxi1=i;
        }
        else{
            if(maxi2==-1) maxi2=i;
            else if(pack[maxi2].t<pack[i].t)maxi2=i;
        }
    }
    int res=0;
    if(maxi1!=-1) {
        res=min(pack[maxi1].num,num);
        pack[maxi1].num=max(0,pack[maxi1].num-num);
    }
    else{
        res=min(pack[maxi2].num,num);
        pack[maxi2].num=max(0,pack[maxi2].num-num);
    }
    return res;
}

inline void update_ammo(int aid,int num){

}

//0 寄 1 ok
inline bool battle(int a,int b){
    if(weap1==0) return 0;

}

//0 寄 1 ok
inline bool update(int row,int col){
    auto cur=tab[row][col];
    if(cur.type) return battle(cur.a,cur.b);//战斗力a,b
    if(cur.a<=9) update_weapon(cur.a);//a类型，b数量
    else{
        // int aim=cur.b*weight[cur.a];
        // while(now+aim>vol){
        //     int tmp=del(aim);
        //     aim-=tmp;
        //     now-=tmp;
        // }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int cmd;
    cin>>n>>m>>vol>>cmd;
    vol*=10;
    for(int i=1;i<=n;i++) {
        int a,b,c;
        cin>>a>>b;
        int row=(i-1)/n+1;
        int col=(i%n)+1;
        if(a==17){
            cin>>c;
            tab[row][col]={true,b,c};
        }
        else tab[row][col]={false,a,b};
    }

    int mvr[]={0,-1,1,0,0};
    int mvc[]={0,0,0,-1,1};
    int row=1,col=1;
    if(!update(row,col)) return 0;
    while(cmd--){
        int op;
        cin>>op;

    }
}