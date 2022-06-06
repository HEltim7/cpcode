//use to transfer inch to centimeter
#include <stdio.h>
#include <math.h>
int main()
{
    int w, h, inches;
    float width, height;
    printf("please enter screen proportion(w:h):");
    scanf("%d%d", &w, &h);
    printf("please enter screen size:");
    scanf("%d", &inches);
    width = w * sqrt(inches * inches * 1. / (w * w + h * h)) * 2.54;
    height = h * sqrt(inches * inches * 1. / (w * w + h * h)) * 2.54;
    printf("w:%.2fcm h:%.2fcm", width, height);
    getchar();
    getchar();
    return 0;
}