/*
	Name: 		Shijie Ren
	Instructor: Li Liang
	Date: 		Oct 15, 2020
	Program: 	Project1/list.h
	Info: 		Header File for the LinkedList class
*/

#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>
#include <cstring>
#include <fstream>
#include "song.h"
#include "artist.h"
using namespace std;

class LinkedList
{
private:
    struct node
    {
        node(artist& anartist)
        {
            a = anartist;
            prev = next = nullptr;
        }
        node(song &asong){
            s = asong;
            prev = next = nullptr;
        }
        ~node(){
			prev = next = nullptr;
		}
        artist a;
        song s;
		node *next, *prev;
	};
	node *head, *tail;
	int size;

public:
	LinkedList();
	~LinkedList();

    // Add a new artist
	void add(artist& anartist);
    // Add a new song to an artist
    void add(song &asong);

    // Check if the song has less than M views
    int find(int aviews);
    // Delete all songs with less than M views
    void del(int m);

    // Display all artists
    void displayArtists();
    // Display all songs for an artist (in order of popularity)
    void displaySongs();

    void loadArtistFromFile(char * fileName);

    LinkedList loadSongsFromArtist(char * Artist);

    void saveArtistToFile(char *name);

    LinkedList saveSongsToArtist(char * Artist);

    void findSong(node * curr, char* Song);

    void editViewsAndLikes(char *Artist, char *Song);
};

#endif // _LINKED_LIST_
