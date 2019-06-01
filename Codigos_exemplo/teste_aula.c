#include<stdio.h>
#include<stdlib.h>

int main(){

  int u = 3;
  int v;
  int *pu;

  pu = &u;
  v = *pu;

  printf("v = %d\n",v);
}
