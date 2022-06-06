#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define endl '\n'
const int N=1e6+10;

int n,m;
string s;
int fir[N],sec[N],cnt[N];
int sa[N],rk[N],height[N];

void get_sa(){
    for(int i=1;i<=n;i++) cnt[fir[i]=s[i]]++; //统计第一关键字
    for(int i=2;i<=m;i++) cnt[i]+=cnt[i-1]; //计算前缀和
    for(int i=n;i;i--) sa[cnt[fir[i]]--]=i; //基数排序,此时sec[i]=i

    for(int k=1;k<=n;k<<=1){ //k=当前考虑的位数
        int num=0;
        /*
            sec[i] 先存没有第二关键字的,一定最小
            sa[i]-k 排名为i的后缀的下标减去当前考虑的位数
            -> 第二关键字为sa[i]-k的后缀
            -> 有第二关键字的后缀
            => sec=按照第二关键字排序的结果
        */
        for(int i=n-k+1;i<=n;i++) sec[++num]=i; //存储没有第二关键字的
        for(int i=1;i<=n;i++) if(sa[i]>k) sec[++num]=sa[i]-k; //枚举第二关键字
        /*
            sec[i] 第二关键字排第i的后缀
            cnt[i] i的个数
            cnt[fir[i]] 第一关键字排名小于fir[i]的个数,前缀和
            fir[sec[i]] 第二关键字排第i的后缀的第一关键字排名
            cnt[fir[sec[i]]] 小于第二关键字排第i的第一关键字排名的个数
            基数排序：按照第二关键字从后往前枚举，计算当前后缀的排名
            -> sa[cnt[fir[sec[i]]]]=sec[i]
        */
        for(int i=1;i<=m;i++) cnt[i]=0; //清空第二关键字
        for(int i=1;i<=n;i++) cnt[fir[i]]++; //统计第一关键字
        for(int i=2;i<=m;i++) cnt[i]+=cnt[i-1]; //计算前缀和
        for(int i=n;i;i--) sa[cnt[fir[sec[i]]]--]=sec[i],sec[i]=0; //基数排序
        /*
            swap fir<->sec
            sec[i] 下标为i的后缀的第一关键字
            sec[sa[i]] 排名为i的后缀第一关键字
            sec[sa[i]+k] 排名为i的后缀的第二关键字
            fir[sa[i]] 排名为i的后缀的待更新的第一关键字
            将第一关键字和第二关键字合并
        */
        swap(fir,sec);
        fir[sa[1]]=num=1;
        for(int i=2;i<=n;i++)
            fir[sa[i]]=(sec[sa[i]]==sec[sa[i-1]]&&sec[sa[i]+k]==sec[sa[i-1]+k])
                ?num:++num; //离散化
        if(num==n) break;  //已经有序，结束
        m=num;
    }
}

void get_height(){
    for(int i=1;i<=n;i++) rk[sa[i]]=i;
    for(int i=1,k=0;i<=n;i++){
        if(rk[i]==1) continue;
        if(k) k--; //h[i]=height[rk[i]],h[i]>=h[i-1]+1
        int j=sa[rk[i]-1]; //j=排名比i后缀小1的后缀
        while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) k++;
        height[rk[i]]=k;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>s;
    s=' '+s;
    n=s.size()-1,m=(int)'z';
    
    get_sa(),get_height();
    for(int i=1;i<=n;i++) cout<<sa[i]<<" \n"[i==n];
    for(int i=1;i<=n;i++) cout<<height[i]<<" \n"[i==n];
    return 0;
}