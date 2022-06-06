//highset common factor
#include <stdio.h>
int main()
{
    int n, i;
    scanf("%d", &n);
    int data[n], image[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
        image[n] = data[i];
    }
    for (i = 0; i < n - 1; i++)
    {
        while (data[i])
        {
            int t = data[i+1] % data[i];
            data[i+1] = data[i];
            data[i] = t;
        }
    }
    int hcf = data[i];
    printf("%d", hcf);
    return 0;
}