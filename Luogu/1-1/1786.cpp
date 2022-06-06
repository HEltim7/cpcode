#include<iostream>
#include<algorithm>
using namespace std;
int n;

struct bang_data{
    string zhiwei;
    string mingzi;
    int banggong;
    int level;
} bang[120],sortbang[120];

int search(bang_data a){
    for(int i=1;i<=n;i++){
        if(bang[i].mingzi==a.mingzi)
            return i;
    }
    return 0;
}

bool cmp(bang_data a,bang_data b){
    if(a.banggong>b.banggong) return 1;
    return 0;
}

bool cmp2(bang_data a,bang_data b){
    if(a.level>b.level) return 1;
    else if((a.level==b.level)&&search(a)<search(b)) return 1;
    return 0;
}

void output(){
    int hufa=2,zhanglao=4,tangzhu=7,jingying=25;
    for(int i=1;i<=n;i++){
        if(hufa){
            cout<<sortbang[i].mingzi<<' '<<"HuFa"<<' '<<sortbang[i].level<<endl;
            hufa--;
        }
        else if(zhanglao){
            cout<<sortbang[i].mingzi<<' '<<"ZhangLao"<<' '<<sortbang[i].level<<endl;
            zhanglao--;
        }
        else if(tangzhu){
            cout<<sortbang[i].mingzi<<' '<<"TangZhu"<<' '<<sortbang[i].level<<endl;
            tangzhu--;
        }
        else if(jingying){
            cout<<sortbang[i].mingzi<<' '<<"JingYing"<<' '<<sortbang[i].level<<endl;
            jingying--;
        }
        else cout<<sortbang[i].mingzi<<' '<<"BangZhong"<<' '<<sortbang[i].level<<endl;
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>bang[i].mingzi>>bang[i].zhiwei>>bang[i].banggong>>bang[i].level;
        sortbang[i].mingzi=bang[i].mingzi,sortbang[i].zhiwei=bang[i].zhiwei,sortbang[i].banggong=bang[i].banggong,sortbang[i].level=bang[i].level;
        if(bang[i].zhiwei=="BangZhu"||bang[i].zhiwei=="FuBangZhu"){
            cout<<bang[i].mingzi<<' '<<bang[i].zhiwei<<' '<<bang[i].level<<endl;
            i--,n--;
        }
    }
    sort(sortbang+1,sortbang+n+1,cmp);
    if(n>=1) sort(sortbang+1,sortbang+min(3,n+1),cmp2);
    if(n>=3) sort(sortbang+3,sortbang+min(7,n+1),cmp2);
    if(n>=7) sort(sortbang+7,sortbang+min(14,n+1),cmp2);
    if(n>=14) sort(sortbang+14,sortbang+min(29,n+1),cmp2);
    if(n>=29) sort(sortbang+29,sortbang+n+1,cmp2);
    output();
    return 0;
}