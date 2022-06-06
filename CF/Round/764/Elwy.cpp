    #include<iostream>
    #include<algorithm>
    #include<string.h>
    using namespace std;
    #define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
    const int N=1005;
    char s[N][N];
    char p[N];
    bool st[N];
    int n,m;
    int key=0;
    struct lwy1
    {
        int idx;
        int id;
    }two[1005];
    struct lwy2
    {
        int idx;
        int id;
    }three[1005];
    int get_two(char q,char w)
    {
        return (q-'0')*10+(w-'0');
    }
    int get_three(char q,char w,char e)
    {
        return (q-'0')*100+(w-'0')*10+(e-'0');
    }
    void dfs(int q,int step[],int idx)
    {
        //debug(q);
        if(key==1) return ;
        if(q==m)    return ;
        if(q==m+1)
        {
            key=1;
            printf("%d\n",idx);
            for(int i=1;i<=idx;i++)
            {
                int x=step[i];
                if(x>=10000)
                {
                    x-=10000;
                    printf("%d %d %d\n",three[x].idx,three[x].idx+2,three[x].id);
                }
                else
                {
                    printf("%d %d %d\n",two[x].idx,two[x].idx+1,two[x].id);
                    //debug(x);
                }
            }
            return ;
        }
        st[q]=true;
        int x=get_two(p[q],p[q+1]);
        if(two[x].id!=0&&!st[q+2])
        {
            // debug(p[q]);
            // debug(p[q+1]);
            // debug(x);
            step[idx+1]=x;
            dfs(q+2,step,idx+1);
        }

        if(q==m-1) return ;
        int y=get_three(p[q],p[q+1],p[q+2]);
        if(three[y].id!=0&&!st[q+3])
        {
            step[idx+1]=y+10000;
            dfs(q+3,step,idx+1);
        }
    }
    int main()
    {
        freopen64("E.in","r",stdin);
        freopen64("E.lwy","w",stdout);
        int T;
        scanf("%d",&T);

        while(T--)
        {
            memset(two,0,sizeof two);
            memset(three,0,sizeof three);
            memset(st,false,sizeof st);
            key=0;

            scanf("%d%d",&n,&m);

            for(int i=1;i<=n;i++)
            scanf("%s",s[i]+1);

            scanf("%s",p+1);

            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m-1;j++)
                {
                    int x=get_two(s[i][j],s[i][j+1]);
                    two[x].id=i;
                    two[x].idx=j;
                    if(j!=m-1)
                    {
                        int y=get_three(s[i][j],s[i][j+1],s[i][j+2]);
                        three[y].id=i;
                        three[y].idx=j;
                    }
                }
            }

            int step[N]={0};
            dfs(1,step,0);

            if(key==0)
            puts("-1");
        }

    }