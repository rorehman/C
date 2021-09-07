// ECE 209 -- Fall 2019
// Type definition for representing an album

#ifndef ALBUMS_ALBUM_H
#define ALBUMS_ALBUM_H
#include <stdio.h>

struct album {
    char title[150];     // official name of the album
    char artist[150];    // artist who recorded the album
    unsigned int rank;   // rank in the Rolling Stone list
    unsigned int year;   // year of release
    unsigned int genre;  // primary genre -- see encoding below
};

typedef struct album Album;

// bit fields for genre
// an album's genre is a bitmap with one or more bits set
#define BLUES           ((unsigned int) 1)       // 0x001
#define CLASSICAL       ((unsigned int) 2)       // 0x002
#define ELECTRONIC      ((unsigned int) 4)       // 0x004
#define FOLK_COUNTRY    ((unsigned int) 8)       // 0x008
#define FUNK_SOUL       ((unsigned int) 16)      // 0x010
#define HIP_HOP         ((unsigned int) 32)      // 0x020
#define JAZZ            ((unsigned int) 64)      // 0x040
#define LATIN           ((unsigned int) 128)     // 0x080
#define POP             ((unsigned int) 256)     // 0x100
#define REGGAE          ((unsigned int) 512)     // 0x200
#define ROCK            ((unsigned int) 1024)    // 0x400
#define STAGE_SCREEN    ((unsigned int) 2048)    // 0x800

#define GENRE_MAX       STAGE_SCREEN    // value of largest genre code

// standardized strings for genre -- must use these!!
// CSV file is guaranteed to contain these strings
#define BLUES_STR           "Blues"
#define CLASSICAL_STR       "Classical"
#define ELECTRONIC_STR      "Electronic"
#define FOLK_COUNTRY_STR    "Folk & Country"
#define FUNK_SOUL_STR       "Funk / Soul"
#define HIP_HOP_STR         "Hip Hop"
#define JAZZ_STR            "Jazz"
#define LATIN_STR           "Latin"
#define POP_STR             "Pop"
#define REGGAE_STR          "Reggae"
#define ROCK_STR            "Rock"
#define STAGE_SCREEN_STR    "Stage & Screen"

#define GENRE_STR_MAX   14   // strlen of longest genre string

// function prototypes

// given string, return encoded genre
// if error, returns 0
unsigned int stringToGenre(const char *str);
// given encoded genre, write string to str (caller must make sure there's enough space)
// if no error, returns ptr to string; if error, returns NULL (str may have been changed)
// resulting string must list genres in alphabetical order, separated by comma and a single space
char * genreToString(unsigned int g, char *str);

// read the next album from the CSV file, create a new struct album containing the information
// Return value:
// if successful, pointer to allocated and initialized struct
// otherwise, NULL
Album * newAlbumFromFile(FILE* fp);

// print album information to standard output -- see the spec for the format
void printAlbum(const Album*);

#endif //ALBUMS_ALBUM_H
