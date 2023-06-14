#include <stdio.h>

int main()
{
    int m;
    printf("Enter the marks");
    scanf("%d",&m);
    if(m >= 90 && m <= 100 )
    {
        printf("Grade A");
    }
    else if(m >= 75 && m <= 89)
    {
        printf("Grade B");
    }
    else if(m >= 60 && m <= 74)
    {
        printf("Grade C");
    }
    else if(m >= 50 && m <= 59)
    {
        printf("Grade D");
    }
    else if(m >= 0 && m <= 49)
    {
        printf("Grade F");
    }
    
    return 0;
}

