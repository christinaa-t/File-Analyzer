/* Name: Christina Tran
 * Username: cssc2367
 * Project: Assignment 0
 * File: alphabetcount.c 
 *       - This file implements the alphabetlettercount function.
 * Note: This program will read in txt files and count the case sensitive characters
 */

/**
  The alphabetlettercount function counts the frequency of each alphabet letter (A-Z a-z, case sensitive) in all the .txt files under
  directory of the given path and write the results to a file named as filetowrite.
  
  Input: 
      path - a pointer to a char string [a character array] specifying the path of the directory; and
      filetowrite - a pointer to a char string [a character array] specifying the file where results should be written in.
      alphabetfreq - a pointer to a long array storing the frequency of each alphabet letter from A - Z a - z:
      alphabetfreq[0]: the frequency of 'A'
      alphabetfreq[1]: the frequency of 'B'
         ... ...
      alphabetfreq[25]:the frequency of 'Z'
      alphabetfreq[26]:the frequency of 'a'
         ...  ...
      alphabetfreq[51]:the frequency of 'z'
  
  Output: a new file named as filetowrite with the frequency of each alphabet letter written in
  
  Steps recommended to finish the function:
  1) Find all the files ending with .txt and store in filelist.
  2) Read all files in the filelist one by one and count the frequency of each alphabet letter only (A-Z a - z). The array 
  long alphabetfreq[] always has the up-to-date frequencies of alphabet letters counted so far. 
  3) Write the result in the output file: filetowrite in following format: 
  
     letter -> frequency
     
     example:
     A -> 200
     B -> 101
     ... ...
     
  Assumption:  
  1) You can assume there is no sub-directory under the given path so you don't have to search the files 
  recursively.    
  2) Only .txt files are counted and other types of files should be ignored.
  
*/

#include "count.h"
#include <stdio.h> 
#include <string.h>
#include <dirent.h>

void alphabetlettercount(char *path, char *filetowrite, long alphabetfreq[]) {

   int c = 0;
   //Path length
   char file_Path[256] = "../data/";
   //Opens and read the data folder in directory 
   FILE *in_File = fopen(file_Path, "r"); 
   
   //Creates a directory stream  
   DIR *dirp;
   //Structure type used to return info. about directory entries
   struct dirent *entry;
   //Opens the directory stream
   dirp = opendir(path); 

   while ((entry = readdir(dirp)) != NULL) {
      //Searches for substring .txt in file name
      if (strstr(entry->d_name, ".txt")) { 
         char file_Path[256] = "../data/";
         //Appends file name to the file path
         strcat(file_Path, entry->d_name);
         in_File = fopen(file_Path, "r"); 
         while ((c = fgetc(in_File))!= EOF) {
            //Counting and storing upper case letter frequency
            if (c >= 'A' && c <= 'Z') {
               alphabetfreq[c - 'A']++;
            }
            //Counting and storing lower case letter frequency
            else if (c >= 'a' && c <= 'z') {
               alphabetfreq[c - 'a' + 26]++;
            }
         }
         fclose(in_File); 
      }      
   }
	closedir(dirp);
   
   //Writing the results to result.txt in the result folder
   FILE *out_File = fopen(filetowrite, "a");
   if (out_File != NULL) {
      //Prints upper case letter frequency 
      for(int i = 0; i < ALPHABETSIZE/2; i++) {  
         fprintf(out_File, "%c -> %d\n", (char)(i+65), alphabetfreq[i]);
	  }
     //Prints lower case letter frequency
     for(int i = ALPHABETSIZE/2; i < ALPHABETSIZE; i++) { 
         fprintf(out_File, "%c -> %d\n", (char)(i+65 + 6), alphabetfreq[i]);  
	  }
   }

}
