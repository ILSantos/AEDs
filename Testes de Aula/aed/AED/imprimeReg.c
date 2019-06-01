#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file;
    char x;

    file = fopen("arqteste","r");

    x = fgetc(file);

    while(!feof(file)){
        printf("%c", x);
        x = fgetc(file);

    }
}
