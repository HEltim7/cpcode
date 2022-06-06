#include<stdio.h>
#include<stdlib.h>
//term:choose->input->output
float main()
{
    //choose method
    float mth,inp1,inp2,result,output;
    float addition(float,float),multiplication(float,float),subtraction(float,float),division(float,float);
    //void exit(0)
    printf("chose operation method\n1 -> +++\n2 -> ---\n3 -> ***\n4 -> ///\n0 -> exit\n");
    scanf("%f",&mth);

    //input data
    printf("input numbers to continue");
    scanf("%f",&inp1);
    printf("input another numbers to continue");
    scanf("%f",&inp2);
    
    //output result
    if(mth==1)
    {
    output=addition(inp1,inp2);
    printf("result:%f\n%s", output,"Done");
    }
    else if(mth==2)
    {
    output=subtraction(inp1,inp2);
    printf("result:%f\n%s", output,"Done");
    }
    else if(mth==3)
    {
    output=multiplication(inp1,inp2);
    printf("result:%f\n%s", output,"Done");
    }
    else if(mth==4)
    {
     output=division(inp1,inp2);
     printf("result:%f\n%s", output,"Done");
    }
    else if(mth==0)
    {
    //exit(0);
    }
    return 0;
}

//Functions
    float addition (float a,float b)
{
    float result=a+b;
    return result;
}
    float subtraction (float a,float b)
{
    float result=a-b;
    return result;
}

    float multiplication(float a,float b)
{
    float result=a*b;
    return result;
} 
    float division(float a,float b)
{
    float result=a/b;
    return result;
}