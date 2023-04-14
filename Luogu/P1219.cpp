#include<bits/stdc++.h>
using namespace std;
int total,n;
int row[100],column[100],diaglr[100],diagrl[100];

void queen(int i)
{
    if (i>n)
    {
        total++;
        if (total<=3)
        {
            for(int k=1;k<=n;k++)
            {
                cout<<row[k]<<' ';
            }
            cout<<endl;
        }
        return;
    }
    else
    {
        for(int j=1;j<=n;j++)//force search by column
        {
            if (!column[j]&&!diaglr[i-j+n]&&!diagrl[i+j])//available
            {
                row[i]=j;
                column[j]=1;
                diaglr[i-j+n]=1;
                diagrl[i+j]=1;
                queen(i+1);//next
                column[j]=0;
                diaglr[i-j+n]=0;
                diagrl[i+j]=0;
            }
        }
    }
}

int main()
{
    cin>>n;
    queen(1);
    cout<<total;
    return 0;
}