// Rohan Rehman
// ECE 209
// Program 3
// ALbumList functions

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include "AlbumList.h"
#include "Album.h"
#include "csv.h"
#include <stdlib.h>

AlbumNode * final = NULL;
int readAlbumFile(const char *filename) {

    // creates an empty list to hold albums
    AlbumNode* head = NULL;
    char* str = malloc(sizeof(150 * sizeof(char)));
    int count = 0;

    // open text file for reading
    FILE * inFile = NULL;
    inFile = fopen(filename, "r");
    if(inFile == NULL){
        return 0;
    }
    // reads and ignores first row
    for(int i = 0; i < 6; i++){
        getCSVString(str, inFile);
    }

    // use newAlbumFromFile to read the next album info and create a new album structure
    while(!feof(inFile)){
        head = insertAlbum(newAlbumFromFile(inFile), head);
        count++;
    }

    final = head;
    fclose(inFile);
    count--;
    return count;
}
// returns final list
const AlbumNode *allAlbums() {
    return final;
}

AlbumNode * insertAlbum(Album *a, AlbumNode *list) {
    // if list is empty
    if(a == NULL){
        return list;
    }
    AlbumNode *new, *p, *prev;
    new = (AlbumNode *)malloc(sizeof(AlbumNode));
    new->album = a;
    new->next = NULL;
    // if list is null
    if(list == NULL){
        return new;
    }
    p = list;
    prev = NULL;
    // traverse through list until the node can be put in the right spot
    while((p != NULL) && (p->album->rank < a->rank)){
        prev = p;
        p = p->next;
    }
    if(prev == NULL){
        list = new;
    }
    else{
        prev->next = new;
    }
    new->next = p;
    return list;
}

void printAlbums(const AlbumNode *list) {
    // prints album as long as the next node exists and we continue to traverse
    while (list->next != NULL) {
        printAlbum(list->album);
        list = list->next;
    }
    // prints current node
    printAlbum(list->album);
}

const Album * findRank(unsigned int rank) {

    AlbumNode *p = final;
    // traverses through list until rank is found
    while((p != NULL) && (p->album->rank != rank)){
       p = p->next;
    }
    if(p == NULL){
        return 0;
    }
    return p->album;

}

AlbumNode * findYear(unsigned int year) {
    AlbumNode *p = final;
    AlbumNode *head = NULL;
    // traverses through list until matching year is found
    while((p != NULL) ){
        if((p->album->year) == year){
            head = insertAlbum(p->album, head);
        }
        p = p->next;
    }
    return head;
}

AlbumNode * findArtist(const char * match) {
    AlbumNode *p = final;
    AlbumNode *head = NULL;
    // traverses through list until matching artist is found
    while((p != NULL) ){
        if(strcasestr(p->album->artist, match) != NULL){
            head = insertAlbum(p->album, head);
        }
        p = p->next;
    }
    return head;
}

AlbumNode * findGenre(const char * genreWord) {
    AlbumNode *p = final;
    AlbumNode *head = NULL;
    // traverses through list until matching genre is found
    while((p != NULL) ){
        char test[150];
        // convert genre to string
        genreToString(p->album->genre,test);
        if(strcasestr(test, genreWord) != NULL){
            head = insertAlbum(p->album, head);
        }
        p = p->next;
    }
    return head;
}