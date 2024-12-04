#include <stdio.h>
int main()
{
    float m,sum = 0;
    int n;

    printf("enter n");
    scanf("%d",&n);
    int x[n+1],y[n+1];

    printf("enter elements of x");
    for(int i=0;i<n;i++){
        scanf("%d",&x[i]);
    }

    printf("enter elements of y");
    for(int i=0;i<n;i++){
        scanf("%d",&y[i]);
    }

    printf("enter x where you want to find y");
    scanf("%f",&m);
    
    for(int i=0;i<n;i++){
        float p=1;
        for(int j=0;j<n;j++){
            if(i!=j){
                p=p*(m-x[j])/(x[i]-x[j]);
            }
        }
        sum=sum+(p*y[i]);
    }
    
    printf("answer %f",sum);
    return 0;
}
