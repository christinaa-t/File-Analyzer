#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 

int main() {
    int count[5];
    memset(&count[0], 0, sizeof(count));
    
    int k = 0;
    int c = 0; 
    int d = 0;

    FILE *inFile = fopen("test_count.txt", "r");

    if (inFile == NULL) {
        printf("Cannot open file");
    }
    while ((c = fgetc(inFile))!= EOF) {
        if (c == '.' || c == ',' || c == ':' || c == ';' || c == '!') {
            ++count[c];
        }  
    }

    for (k=0; k < 5; k++ ) {
        printf("Count of '%c' is %d\n", k, count[k]);
    }
   
    
    fclose(inFile);
    
    return 0;

}