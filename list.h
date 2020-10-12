#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>
#include <cstring>
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

	void add(artist& anartist);
    int find(int aviews);
    void add(song &asong);

    // node *split(node *head);
    // node *merge(node *first, node *second);
    // node *mergeSort(node *head);
    void del(int m);

    void displayArtists();
    void displaySongs();
};

#endif // _LINKED_LIST_
