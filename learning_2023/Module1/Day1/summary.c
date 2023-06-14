#include <stdio.h>

int main()
{
    int mp,mc,mm,total,roll_no;
    float perc;
    char name;
    printf("Enter the name");
    scanf("%s",&name);
    printf("Enter the roll no");
    scanf("%d",&roll_no);
    printf("Enter the marks of physics");
    scanf("%d",&mp);
    printf("Enter the marks of chemistry");
    scanf("%d",&mc);
    printf("Enter the marks of mathematics");
    scanf("%d",&mm);
    total = mp + mc + mm;
    perc = (total/3);
    printf("The total marks is ...%d",total);
    printf("The percentage marks is ...%f",perc);
    
    return 0;
    
}


