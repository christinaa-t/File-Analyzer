/* Name: Christina Tran
 * Username: cssc2367
 * Project: Assignment 0
 * File: specialcharcount.c 
 *       - This file implements the specialcharcount function.
 * Note: This program will read in txt files and count the 5 special characters
 */

/**
  The specialcharcount function counts the frequency of the following 5 special characters:
  ','   '.'   ':'    ';'    '!'
   
  in all the .txt files under directory of the given path and write the results to a file named as filetowrite.
  
  Input: 
  
      path - a pointer to a char string [a character array] specifying the path of the directory; and
      filetowrite - a pointer to a char string [a character array] specifying the file where results should be written in.
      alphabetfreq - a pointer to a long array storing the frequency of the above 5 special characters
      
      charfreq[0]: the frequency of ','
      charfreq[1]: the frequency of '.'
      charfreq[2]: the frequency of ':'
      charfreq[3]: the frequency of ';'
      charfreq[4]: the frequency of '!'

  
  Output: a new file named as filetowrite with the frequency of the above special characters written in
  
  Steps recommended to finish the function:
  1) Find all the files ending with .txt and store in filelist.
  2) Read all files in the filelist one by one and count the frequency of each alphabet letter only (a - z). The array 
  long alphabetfreq[] always has the up-to-date frequencies of alphabet letters counted so far. If the letter is upper case, convert
  it to lower case first. 
  3) Write the result in the output file: filetowrite in following format: 
  
     character -> frequency
     
     example:
     , -> 20
     . -> 11
     : -> 20
     ; -> 11
     ! -> 12     
     
  Assumption:  
  1) You can assume there is no sub-directory under the given path so you don't have to search the files 
  recursively.    
  2) Only .txt files are counted and other types of files should be ignored.
  
*/

#include "count.h"
#include <stdio.h> 
#include <string.h>
#include <dirent.h>

void specialcharcount(char *path, char *filetowrite, long charfreq[]) {

  int c = 0;
  //Path Length
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
    //Searches for substring ".txt" in file name
    if (strstr(entry->d_name, ".txt")) { 
      char file_Path[256] = "../data/";
      //Appends file name to the file path
      strcat(file_Path, entry->d_name);
      in_File = fopen(file_Path, "r"); 
      while ((c = fgetc(in_File))!= EOF) {
        //Counts and stores the 5 special characters 
         if (c == ',') {
          charfreq[0]++;
        }
        if (c == '.') {
          charfreq[1]++;
        }
        if (c == ':') {
          charfreq[2]++;
        }
        if (c == ';') {
          charfreq[3]++;
        }
        if (c == '!') {
          charfreq[4]++;
        }     
      }
    fclose(in_File); 
    }
  }
	closedir(dirp);

  //Writing the results of special character count to specialresult.txt in the result folder
   FILE *out_File = fopen(filetowrite, "a");
   if (out_File != NULL) {
     for(int i = 0; i < SPECIALCHARSIZE; i++) {
       switch(i) {
         case 0:
	  			fprintf(out_File, ", -> %d\n", charfreq[i]);
	  			break;
	  		case 1:
	  			fprintf(out_File, ". -> %d\n", charfreq[i]);
	  			break;
	  		case 2:
	  			fprintf(out_File, ": -> %d\n", charfreq[i]);
	  			break;
	  		case 3:
	  			fprintf(out_File, "; -> %d\n", charfreq[i]);
	  			break;
	  		case 4:
	  			fprintf(out_File, "! -> %d\n", charfreq[i]);
	  			break;
	  	}	  	
	  }
      
  }
		
}


