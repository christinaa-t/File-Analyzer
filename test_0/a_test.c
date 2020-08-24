#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 

int main() {

    /*int count_lower[26];
    int count_upper[26];
    memset(&count_lower[0], 0, sizeof(count_lower));
    memset(&count_upper[0], 0, sizeof(count_upper)); */

   int count[52];
   memset(&count[0], 0, sizeof(count)); 
    
    int k = 0;
    int c = 0; 
    int d = 0;

    FILE *inFile = fopen("test_count.txt", "r");

    if (inFile == NULL) {
        printf("Cannot open file");
    }
    /* while ((c=fgetc(inFile))) {
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
    
    return 0; */


    /* while (1) {
        c = getc(inFile);
        if (c == EOF) {
            break;
        }
        else {
            count[c]++;
        }
    }
    for (k=0; k < 52; k++) {
        if (count[k] >= 0) {
            printf("Number of character %c is %d\n", (char)k, count[k]);
        }
    }
    fclose(inFile);
    
    return 0; */
    
     /*while ((c = fgetc(inFile))!= EOF) {
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']++;
        } 
    }
    while ((d = fgetc(inFile))!= EOF) {
        if (d >= 'A' && d <= 'Z') {
            count[d - 'A']++;
        }
    } */
    while ((c = fgetc(inFile))!= EOF) {
        if (c >= 'A' && c <= 'Z') {
            ++count[c - 'A'];
        }
        else if (c >= 'a' && c <= 'z') {
            ++count[c - 'a' + 26];
        }
    }
   

    for (char i = 'a'; i <= 'z'; i++) {
        printf("Count of '%c' is %d\n", i, count[i - 'a' + 26]);
    }
    for (char j = 'A'; j <= 'Z'; j++) {
        printf("Count of '%c' is %d\n", j, count[j - 'A']);
    }

    fclose(inFile);
    
    return 0;

}