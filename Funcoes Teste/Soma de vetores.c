#include <stdio.h>
void main() {
  const n = 3; 
  int a[n], b[n], c[n]; 
  int i;
	  for (i=0; i<n; i++) {
    	printf("Digite os elementos do vetor 'a': ", (i+1), n);
    	scanf("%d", &a[i]);
  }

	  printf("\n\n");

  	for (i=0; i<n; i++) {
    	printf("Digite os elementos do vetor 'b': ", (i+1), n);
    	scanf("%d", &b[i]);
  }

  	for (i=0; i<n; i++) {
    	c[i] = a[i] + b[i];
  }

  printf("\n\ni- a[i]   b[i]   c[i] = a[i] + b[i]\n");
  printf("===================================\n");
  for (i=0; i<n; i++) {
    printf("%d- %4d   %4d   %4d\n", i, a[i], b[i], c[i]);
  }
  printf("===================================\n");
}
