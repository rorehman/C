// Rohan Rehman
// ECE 209
// Program 3
// Album functions

#include <stdio.h>
#include <string.h>
#include "Album.h"
#include <stdlib.h>
#include "csv.h"

unsigned int stringToGenre(const char *str) {
    unsigned int value = 0;
    int x = 0;  // string ocunter
    int y = 0;  // comma counter
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == ','){
            y++;
        }
    }
    // value is set to BLUES if not NULL
    if(strstr(str,BLUES_STR)!=NULL){
        x++;
        value = BLUES;
    }
    if(strstr(str,CLASSICAL_STR)!= NULL){
        x++;
        value += CLASSICAL;
    }
    if(strstr(str,ELECTRONIC_STR)!= NULL){
        x++;
        value += ELECTRONIC;
    }
    if(strstr(str,FOLK_COUNTRY_STR)!= NULL){
        x++;
        value += FOLK_COUNTRY;
    }
    if(strstr(str,FUNK_SOUL_STR)!= NULL){
        x++;
        value += FUNK_SOUL;
    }
    if(strstr(str,HIP_HOP_STR)!= NULL){
        x++;
        value += HIP_HOP;
    }
    if(strstr(str,JAZZ_STR)!= NULL){
        x++;
        value += JAZZ;
    }
    if(strstr(str,LATIN_STR)!= NULL){
        x++;
        value += LATIN;
    }
    if(strstr(str,POP_STR)!= NULL){
        x++;
        value += POP;
    }
    if(strstr(str,REGGAE_STR)!= NULL){
        x++;
        value += REGGAE;
    }
    if(strstr(str,ROCK_STR)!= NULL){
        x++;
        value += ROCK;
    }
    if(strstr(str,STAGE_SCREEN_STR)!= NULL){
        x++;
        value += STAGE_SCREEN;
    }

    // makes sure only one less comma than string
    if(y+1 != x){
        return 0;
    }
    if (value > 0){
        return value;
    }
    else {
        return 0;
    }
}

char * genreToString(unsigned int g, char *str) {
    int count = 0;  // counter
    char ending[3] = ", ";
    unsigned int pass = 0;

    // is BLUES?
    if((BLUES & g) > 0){    // yes if > 0
        strcpy(str,BLUES_STR);  // copy BLUES string into str
        count ++;   // increase counter
    }
    if((CLASSICAL&g) > 0){
        if(count == 0){
            strcpy(str,CLASSICAL_STR);
            count++;
        }
        // replace ending
        else{
            strcat(str, ending);
            strcat(str,CLASSICAL_STR);
            count++;
        }
    }
    if((ELECTRONIC&g) > 0){
        if(count == 0){
            strcpy(str,ELECTRONIC_STR);
            count++;
        }
        else{
            strcat(str, ending);
            strcat(str,ELECTRONIC_STR);
            count++;
        }
    }
    if((FOLK_COUNTRY&g) > 0){
        if(count == 0){
            strcpy(str,FOLK_COUNTRY_STR);
            count++;
        }
        else{
            strcat(str, ending);
            strcat(str,FOLK_COUNTRY_STR);
            count++;
        }
    }
    if((FUNK_SOUL&g) > 0){
        if(count == 0){
            strcpy(str,FUNK_SOUL_STR);
            count++;
        }
        else{
            strcat(str, ending);
            strcat(str,FUNK_SOUL_STR);
            count++;
        }
    }
    if((HIP_HOP&g) > 0){
        if(count == 0){
            strcpy(str,HIP_HOP_STR);
            count++;
        }
        else{
            strcat(str, ending);
            strcat(str,HIP_HOP_STR);
            count++;
        }
    }
    if((JAZZ&g) > 0){
        if(count == 0){
            strcpy(str,JAZZ_STR);
            count++;
        }
        else{
            strcat(str, ending);
            strcat(str,JAZZ_STR);
            count++;
        }
    }
    if((LATIN&g) > 0){
        if(count == 0){
            strcpy(str,LATIN_STR);
            count++;
        }
        else{
            strcat(str, ending);
            strcat(str,LATIN_STR);
            count++;
        }
    }
    if((POP&g) > 0){
        if(count == 0){
            strcpy(str,POP_STR);
            count++;
        }
        else{
            strcat(str, ending);
            strcat(str,POP_STR);
            count++;
        }
    }
    if((REGGAE&g) > 0){
        if(count == 0){
            strcpy(str,REGGAE_STR);
            count++;
        }
        else{
            strcat(str, ending);
            strcat(str,REGGAE_STR);
            count++;
        }
    }
    if((ROCK&g) > 0){
        if(count == 0){
            strcpy(str,ROCK_STR);
            count++;
        }
        else{
            strcat(str, ending);
            strcat(str,ROCK_STR);
            count++;
        }
    }
    if((STAGE_SCREEN&g) > 0){
        if(count == 0){
            strcpy(str,STAGE_SCREEN_STR);
            count++;
        }
        else{
            strcat(str, ending);
            strcat(str,STAGE_SCREEN_STR);
            count++;
        }
    }
   pass = stringToGenre(str);
    if(pass != g){
        return NULL;
    }
    else if(pass == 0){
        return NULL;
    }
    else{
        return str;
    }
}

Album * newAlbumFromFile(FILE* fp) {

   // char genre_str[150];    // holds string from genre, which will later be converted into an integer and stored
    int num = 0, pass = 0;
    char ch[150];
    unsigned int i;
    // if no file is found
    if(fp == NULL){
        return NULL;
    }

    struct album *a = malloc(sizeof(struct album));

    // store return value of getCSVInt
    pass = getCSVInt(&num, fp);
    // check for pass or fail
    if(pass == 0){
        return NULL;
    }
    else{
        a->rank = num;  // stored number read into rank in struct
    }
    pass = getCSVInt(&num, fp);
    if(pass == 0){
        return NULL;
    }
    else{
        a->year = num;
    }

    pass = getCSVString(ch, fp);
    if(pass == 0){
        return NULL;
    }
    else{
        for(i = 0; i < strlen(ch); i++){
            a->title[i] = ch[i];    // stores string in character array
        }
    }

    pass = getCSVString(ch, fp);
    if(pass == 0){
        return NULL;
    }
    else{
        for(i = 0; i < strlen(ch); i++){
            a->artist[i] = ch[i];
        }
    }

    pass = getCSVString(ch, fp);
    if (pass == 0){
        return NULL;
    }
    else{
        a->genre = stringToGenre(ch);    // conversion of string to number by calling stringToGenre function
    }
    getCSVString(ch, fp);

    return a;

}

void printAlbum(const Album* a) {

    char ch[100];
    genreToString(a->genre, ch);

    // prints in order
    printf("#%d: %s\n", a->rank, a->title);
    printf(">> %s (%d) :: %s\n", a->artist, a->year, ch);

}