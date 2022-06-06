//埃氏筛
int isnp[10000] = {1, 1};

void prime(int ip)
{
    for (int i = 2; i * i < ip; i++)
        if (!isnp[i])
            for (int j = i * i; j < ip; j += i)
                isnp[j] = 1;
}