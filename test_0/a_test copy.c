#include <stdio.h>
#include <stdlib.h>

#define ALPHABETSIZE 52  

int main() {

    int count[ALPHABETSIZE] = {0};
    int k = 0;
    int c = 0; 

    FILE *inFile = fopen("test_count.txt", "r");

    if (inFile == NULL) {
        printf("Cannot open file");
    }
    while ((c=fgetc(inFile))) {
        if (c==EOF) {
            break;
        }
        else {
            count[c]++;
        }
    }
    for (k=0; k < ALPHABETSIZE; k++) {
        if (count[k] >= 0) {
            printf("%c: %d", k, count[k]);
        }
    }
    fclose(inFile);
    
    return 0;

}