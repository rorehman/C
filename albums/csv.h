// ECE 209 -- Fall 2019
// csv.h: functions related to CSV files

#ifndef ALBUMS_CSV_H
#define ALBUMS_CSV_H

#include <stdio.h>

// getCSVString: Extract the next field from a CSV file, as a string
// Field is stored into str -- caller must be sure that str is large enough.
// Return values:
// 0 = no field extracted (could be error, or could be EOF)
// 1 = success, field extracted
// if 0 returned str could be changed, but caller should ignore
// File pointer fp must be moved to the beginning of the next field to be read

int getCSVString(char * str, FILE* fp);

// getCSVInt: Extract the next field from a CSV file as a decimal integer
// Caller provides the address where integer should be stored
// Return value:
// 0 = no integer extracted (could be error, or could be EOF)
// 1 = success, field extracted
// if 0 returned, *num could be changed, but caller should ignore
// File pointer fp must be moved to the beginning of the next field to be read

int getCSVInt(int * num, FILE* fp);

#endif //ALBUMS_CSV_H
