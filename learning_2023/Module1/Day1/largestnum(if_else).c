#include<stdio.h>
#include<stdlib.h>

int main() {
  int n1, n2, max;
  n1 = 30;
  n2 = 20;

  if (n1 > n2) 
  {
    max = n1; 
  } 
  else if (n2 > n1)
  {
    max = n2; 
  }

  printf("Maximum Number from %d and %d is %d", n1, n2, max); 
  return 0;
}

    
