// ECE 209 -- Fall 2019
// Types and functions related to album lists
// (1) readAlbumFile reads all the information from a CSV file and "remembers" for later requests
// (2) other functions: extract information from the collection and return a list of albums

#ifndef ALBUMS_ALBUMLIST_H
#define ALBUMS_ALBUMLIST_H

#include "Album.h"


struct album_node {
    Album* album;
    struct album_node *next;
};

typedef struct album_node AlbumNode;

// read album collection from CSV file
// overwrites previous collection, if any
// Return value:
// 0 = error, unable to open file
// otherwise, returns the number of albums in collection
int readAlbumFile(const char *filename);

// return a const list of all albums
// collection is the last CSV file read
const AlbumNode *allAlbums();

// insert album into a list, sorted by rank
// initial list may be empty
// returns head of modified list
AlbumNode * insertAlbum(Album *a, AlbumNode *list);

// print album list (uses printAlbum from Album.h)
void printAlbums(const AlbumNode *list);

// return album with the specified rank (if exists)
const Album * findRank(unsigned int rank);

// return list of albums from given year (sorted by rank)
// must be a list that can be deleted
AlbumNode * findYear(unsigned int year);

// return list of albums for given artist (sorted by rank)
// matching is case-insensitive and partial match is allowed
// must be a list that can be deleted
AlbumNode * findArtist(const char * match);

// return list of albums of a given genre (sorted by rank)
// case-insensitive search, but must match complete word, no partial match
// (e.g. "r" does NOT match "Rock", "folk" does match "Folk & Country")
// must be a list that can be deleted
AlbumNode * findGenre(const char * genreWord);

#endif //ALBUMS_ALBUMLIST_H
