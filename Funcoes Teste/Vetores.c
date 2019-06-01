#include <stdio.h>

void main() {
  const n = 3; 
  int a[n], b[n]; 
  int i; 

  for (i=0; i<n; i++) {
    printf("Digite os elementos do vetor: ", (i+1), n);
    scanf("%d", &a[i]);
  }

  for (i=0; i<n; i++) {
    b[i] = a[i];
  }

  printf("\n\n");
  for (i=0; i<n; i++) {
    printf("a[%d] = %3d   b[%d] = %3d\n", i, a[i], i, b[i]);
  }
}
