#include<iostream>
using namespace std;

const int N=110;
int n;
double cmb[N];
double cmbsum;

void getcmb()
{
    cmb[0] = 1;
    cmb[n] = 1;
    for (int i = 1; i <= n + 1 >> 1; i++)
    {
        cmb[i] = cmb[i - 1] * (n - i + 1) / i;
        cmb[n - i] = cmb[i];
    }
    for (int i = 1; i <= n; i++)
        cmbsum += cmb[i];
    // for(int i=1;i<=n;i++) debug(i),debug(cmb[i]);
}

int main(){
    cin>>n;
    getcmb();
    return 0;
}