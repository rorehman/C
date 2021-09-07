// Rohan Rehman
// ECE 209
// Program 3
// cvs read functions

#include <stdio.h>
#include <string.h>
#include "csv.h"


int getCSVString(char * str, FILE* fp) {

    char ch;
    int count = 0;
    // continues to scan while not the end of file
    while(!feof(fp)){
        fscanf(fp, "%c", &ch);

        // check to allow commas in quotes to be read
        if(ch == '\"'){
            while(!feof(fp)){
                fscanf(fp, "%c", &ch);
                if(ch == '\"'){
                    fscanf(fp, "%c", &ch);
                    if(ch == ',' || ch == '\0' || ch == '\n'){
                        break;
                    }
                }
                str[count] = ch;
                count++;
            }
        }
        if(ch == ',' || ch == '\0' || ch == '\n'){
            break;
        }
        str[count] = ch;
        count++;
    }
    str[count] = '\0';
    if(count == 0) {
        return 0;
    }
    else{
        return 1;
    }
}

int getCSVInt(int * num, FILE* fp) {

  char ch;

  // reads file for number
  if(fscanf(fp, "%d", num) != EOF){
      fscanf(fp, "%c", &ch);
      return 1;
  }
  else {
      return 0;
  }
}