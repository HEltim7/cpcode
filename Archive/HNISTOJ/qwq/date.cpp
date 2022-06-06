/*
    Info:All about date
    Function:
            +计算闰年
            +计算任意两个日期之间的间隔
            +计算某日期x天后的日期
            +判断某天是星期几
            +updating...
    Note:此模型为HEltim7自用模板库的一部分
*/
#include<iostream>
#include<cstring>
using namespace std;
#define getyear(in) isLeap[in]?366:365//返回in年的天数
bool isLeap[10010];//闰年
int month[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//平年月
int monthL[13]={0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//闰年月

//判断闰年,本程序里3200倍数为平年
void getLeap(int n){
    //memset(isLeap,0,10000);//init
    for(int i=4;i<=n;i+=4){
        if(i%100!=0) isLeap[i]=1;
        else if(i%400==0&&i%3200!=0) isLeap[i]=1;
        //else if(i%172800==0) isLeap[i]=1;
    }
}

//<CORE> 此函数用于计算两个日期间的间隔
//输入起始日期y0,m0,d0和结束日期y,m,d,输出间隔
long howlong(int y0,int m0,int d0,int y,int m,int d){
    long sum=0;
    bool exchange=0;
    if((y0>y)||(y0==y&&m0>m)||(y0==y&&m0==m&&d0>d)){
        exchange=1;
        int t;
        t=y0; y0=y; y=t;
        t=m0; m0=m; m=t;
        t=d0; d0=d; d=t;
    }
    ///////////////////////////////////
    for(int i=y0+1;i<=y-1;i++){
        if(isLeap[i]) sum+=366;
        else sum+=365;
    }
    if(y-y0>=1){
        if(isLeap[y0]){
            for(int i=m0+1;i<=12;i++){
                sum+=monthL[i];
            }
            sum+=monthL[m0]-d0;
        }
        else
        {
            for(int i=m0+1;i<=12;i++){
                sum+=month[i];
            }
            sum+=month[m0]-d0;
        }
        ///////////////////////////////
        if(isLeap[y]){
            for(int i=m-1;i>=1;i--){
                sum+=monthL[i];
            }
            sum+=d;
        }
        else
        {
            for(int i=m-1;i>=1;i--){
                sum+=month[i];
            }
            sum+=d;
        }
    }
    ///////////////////////////////////
    else
    {
        if(isLeap[y]){
            for(int i=m0+1;i<=m-1;i++){
                sum+=monthL[i];
            }
            if(m-m0>=1){
                sum+=monthL[m0]-d0;
                sum+=d;
            }
            else
                sum+=d-d0;
        }
        ///////////////////////////////
        else
        {
            for(int i=m0+1;i<=m-1;i++){
                sum+=month[i];
            }
            if(m-m0>=1){
                sum+=month[m0]-d0;
                sum+=d;
            }
            else
                sum+=d-d0;
        }
    }
    if(exchange) return -sum;
    return sum;
}

//此函数基于howlong,用于计算给定日期space天后是哪天
//输入起始日期y0,m0,d0和间隔space,输出目标日期
void whatday(int y0,int m0,int d0,int space){
    int tmp=howlong(y0,m0,d0,y0,12,31);
    int y=y0,m=1,d=1,tmpspace=space;
    if(tmp+getyear(y+1)<=space){
        while(tmpspace-tmp>=(getyear(y+1))){
            tmpspace-=getyear(y+1);
            y++;
        }
    }
    if(howlong(y0,m0,d0,y,12,31)<space){
        y++;
    }
    //规模较小，直接暴力查找
    tmp=howlong(y0,m0,d0,y,m,d);
    while(tmp!=space||m>12){
        if(howlong(y0,m0,d0,y,m+1,d)>space){
            d=(isLeap[y]?monthL[m]:month[m])-(howlong(y0,m0,d0,y,m+1,d)-space-1);
            break;
        }
        tmp=howlong(y0,m0,d0,y,++m,d);
    }
    cout<<"[info]The date is:"<<y<<'-'<<m<<'-'<<d<<endl;
    return;
}

//基于howlong用于判断星期几
//输入日期y,m,d输出星期几,适用100年之后
int getweek(int y,int m,int d){
    //100,1,1 Friday
    long tmp=howlong(100,1,1,y,m,d);
    return (4+tmp%7)%7+1;
}

void start(){
    cout<<"[info]Choose options to start:"<<endl;
    cout<<"<1> calculate how long one day between another day"<<endl;
    cout<<"<2> get the date that one day after several days"<<endl;
    cout<<"<3> determine the day of the week"<<endl;
    cout<<"<0> exit"<<endl;
    cout<<"input format: 1,2or3"<<endl;
    int mth;
    while(cin>>mth&&mth!=0){
        if(mth!=1&&mth!=2&&mth!=3){
            cout<<"[Error]:Illegal input,please enter again"<<endl;
            continue;
        }
        long in1,in2,in3,in4,in5,in6;
        cout<<"[info]Please enter data to continue"<<endl;
        if(mth==1){
            cout<<"Input format:<year1> <month1> <day1> <year2> <month2> <day2>,example:\"2000 1 1 2077 12 31\""<<endl;
            cin>>in1>>in2>>in3>>in4>>in5>>in6;
            cout<<"[info]The result is:"<<howlong(in1,in2,in3,in4,in5,in6)<<endl;
        }
        else if(mth==2){
            cout<<"Input format:<year> <month> <day> <space>,example:\"2000 1 1 1000\""<<endl;
            cin>>in1>>in2>>in3>>in4;
            whatday(in1,in2,in3,in4);
        }
        else if(mth==3){
            cout<<"Input format:<year> <month> <day>,example:\"2077 1 1\""<<endl;
            cin>>in1>>in2>>in3;
            int tmp=getweek(in1,in2,in3);
            cout<<"[info]The day is:";
            switch (tmp)
            {
            case 1:
                cout<<"Monday"<<endl;
                break;
            case 2:
                cout<<"Tuesday"<<endl;
                break;
            case 3:
                cout<<"Wednesday"<<endl;
                break;
            case 4:
                cout<<"Thursday"<<endl;
                break;
            case 5:
                cout<<"Friday"<<endl;
                break;
            case 6:
                cout<<"Saturday"<<endl;
                break;
            case 7:
                cout<<"Sunday"<<endl;
                break;
            default:
                break;
            }
        }
        cout<<"[info]Enter number to continue,or enter 0 to EXIT"<<endl;
    }
}

int main(){
    getLeap(10000);
    start();
    return 0;
}

/*test data:*/
/*
    in [howlong] :
    1975,6,3,2077,2,19 -->37152
    1975,6,3,1976,2,19 -->261
    1975,6,3,1975,8,19 -->77
    2077,6,3,2077,6,4  -->1
    1975,6,3,2077,2,19 -->-37152
    1975,6,3,1976,2,19 -->-261
    1975,6,3,1975,8,19 -->-77
    2077,6,3,2077,6,4  -->-1
    2020,3,4,2026,7,1  -->2310

    in [getweek]
    2020,12,12 -->6
    2020,1,9   -->4
    2021,8,31  -->2
    
    in[whatday]
    2020,1,1,1000 -->2022,9,27
    2020,1,31,1   -->2020,2,1
    2020,3,4,2333 -->2020,7,24
    1000,1,1,999999->3737,11,28
    1000,1,1,700000->2916,7,15
*/