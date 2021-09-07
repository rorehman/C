// ECE 209 -- Fall 2019
// Program 3: Rolling Stone's Top 500 Albums (2012)
// The program reads a CSV file with information from Rolling Stone Magazine's list of the top 500 albums
// of all time, compiled in 2012.  The user interface provides commands for extracting information
// from the list.

#include <stdio.h>
#include <string.h>
#include "Album.h"
#include "AlbumList.h"

// user interface for ALbums program

int main() {
    char command[10] = "";
    char info[200] = "";  // no title, artist, or genre string should be larger than 200 characters
    unsigned int num = 0;
    int status = 0;
    const AlbumNode *all = NULL;
    AlbumNode *albums = NULL;  // non-const list returned by functions

    while (1) {
        printf("Command: ");
        fflush(stdout);
        scanf("%9s", command);

        if (!strcmp(command, "read")) {
            printf("File name: ");
            fflush(stdout);
            scanf("%199s", info);
            status = readAlbumFile(info);
            if (!status) {
                printf("ERROR: Could not read file %s\n", info);
            }
            else {
                printf("Read %d albums from %s\n", status, info);
            }
        }
        else if (!strcmp(command, "all")) {
            all = allAlbums();
            if (!all) {
                printf("No albums in current list\n");
            }
            else {
                printAlbums(all);
            }
        }
        else if (!strcmp(command, "rank")) {
            printf("Desired rank: ");
            fflush(stdout);
            scanf("%u", &num);
            const Album *a = findRank(num);
            if (!a) {
                printf("No album with rank %d found\n", num);
            } else {
                printAlbum(a);
            }
        }
        else if (!strcmp(command, "year")) {
            printf("Desired year: ");
            fflush(stdout);
            scanf("%u", &num);
            albums = findYear(num);
            if (!albums) {
                printf("No albums from year %d found\n", num);
            }
            else {
                printAlbums(albums);
            }
        }
        else if (!strcmp(command, "artist")) {
            printf("Desired artist (one word): ");
            fflush(stdout);
            scanf("%199s", info);
            albums = findArtist(info);
            if (!albums) {
                printf("No albums with artist %s found\n", info);
            }
            else {
                printAlbums(albums);
            }
        }
        else if (!strcmp(command, "genre")) {
            printf("Desired genre (one word): ");
            fflush(stdout);
            scanf("%199s", info);
            albums = findGenre(info);
            if (!albums) {
                printf("No albums in genre %s found\n", info);
            }
            else {
                printAlbums(albums);
            }
        }
        else if (!strcmp(command, "quit")) {
            break;
        }
    }
    return 0;
}