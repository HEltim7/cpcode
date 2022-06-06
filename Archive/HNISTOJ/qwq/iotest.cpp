#include<iostream>
#include<fstream>
#include <ctime>
#include<chrono>
using namespace std;
using namespace std::chrono;
const int N=1e8+10;
int read[N];

int main(){
    // std::ios::sync_with_stdio(0);
    // std::cin.tie(0);
    // std::cout.tie(0);
    freopen("io1e8.txt","r",stdin);
    freopen("out.txt","w+",stdout);

    high_resolution_clock::time_point beforePrintf = high_resolution_clock::now();

    // for(int i=1;i<=1e8;i++) cin>>read[i];
    // for(int i=1;i<=1e8;i++) cout<<read[i];
    for(int i=1;i<=1e8;i++) scanf("%d",&read[i]);
    for(int i=1;i<=1e8;i++) printf("%d",read[i]);


    // fclose(stdout);
    high_resolution_clock::time_point afterPrintf = high_resolution_clock::now();
    duration<double> printfTimeSpan = duration_cast<duration<double>>(afterPrintf - beforePrintf);

    cout<<"Printf Times: " << printfTimeSpan.count() << " seconds.";
    return 0;
}