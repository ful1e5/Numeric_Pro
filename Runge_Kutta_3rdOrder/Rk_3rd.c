#include<stdio.h>
#define MAX 20

float fxy(float x,float y)
{
    return(x*y);
}

int main()
{
    FILE *fp;
    int i=1,count=1;
    float x0,xn,y0,h,xvalue[MAX],yvalue[MAX];
    float k1,k2,k3;
    fp=fopen("rk_3rd_out.dat","w");
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("Runge-Kutta Third Order ");
    fprintf(fp,"Runge-Kutta Third Order ");
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("\nEnter the lower bound of x (x0) :  ");
    fprintf(fp,"\nEnter the lower bound of x (x0) :  ");
    scanf("%f",&x0);
    fprintf(fp,"%f",x0);
    printf("\nEnter the upper bound of x (xn) :  ");
    fprintf(fp,"\nEnter the upper bound of x (xn) :  ");
    scanf("%f",&xn);
    fprintf(fp,"%f",xn);
    printf("\nEnter the value of y(lower)  (y0):  ");
    fprintf(fp,"\nEnter the value of y(lower)  (y0):  ");
    scanf("%f",&y0);
    fprintf(fp,"%f",y0);
    printf("\nEnter the value of h       :  ");
    fprintf(fp,"\nEnter the value of h       :  ");
    scanf("%f",&h);
    fprintf(fp,"%f",h);
    xvalue[i]=x0;
    yvalue[i]=y0;
    for(i=1;xvalue[i]<=xn;i++){
        xvalue[i+1]=xvalue[i]+h;
        count=count+1;
    }
    for(i=1;i<=count;i++){
        k1=h*fxy(xvalue[i],yvalue[i]);
        k2=h*fxy(xvalue[i]+(h/2),yvalue[i]+(k1/2));
        k3=h*fxy(xvalue[i]+h,yvalue[i]-k1+(2*k2));
        yvalue[i+1]=yvalue[i]+(1/6)*(k1+(4*k2)+k3);
    }
    printf("\n\n");
    fprintf(fp,"\n\n");
    printf("The complete solution of the differential f(xy) is ");
    fprintf(fp,"The complete solution of the differential f(xy) is ");
    printf("\n\n");
    fprintf(fp,"\n\n");
    for(i=1;i<=count;i++){
        printf(" %d)  %.4f   %.4f  ",i,xvalue[i],yvalue[i]);
        fprintf(fp," %d)  %.4f   %.4f  ",i,xvalue[i],yvalue[i]);
        printf("\n");
        fprintf(fp,"\n");
    }
    fclose(fp);
    return 0;
}