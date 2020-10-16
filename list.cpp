/*
	Name: 		Shijie Ren
	Instructor: Li Liang
	Date: 		Oct 15, 2020
	Program: 	Project1/list.cpp
	Info: 		Implementation of LinkedList class - contains the main method
                involving pointers, recursion and any LinkedList methods.
*/

#include "list.h"
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CHAR = 250;

//implementations for the member functions of Doubly LinkedList class
LinkedList::LinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList(){
    node *curr = head;
    while (curr)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }
    size = 0;
}

/**
 * LinkedList 
 * 
 * @param  {artist} anartist 
 */
void LinkedList::add(artist& anartist){
    cout << "...Calling add method on artist only..." << endl;
    node *newNode = new node(anartist);
    if (!head){
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
    }
    size++;
}

/**
 * LinkedList 
 * 
 * @param  {int} aviews : 
 * @return {int}        : how many songs in the list has less than M views
 */

int LinkedList::find(int aviews){
    cout << "...Calling find method on..." << aviews << endl;
    node *curr = head->next;
    int count = 0;
    if (curr->s.getViews() < aviews && curr != NULL){ 
        ++count;
        cout << count << endl;
        return count;
    }
    else{
        if (curr->next != NULL){
            head = head->next;
            return find(aviews);
        }
        else{
            return false;
        }
    }
}

/**
 * LinkedList 
 * 
 * @param  {song} asong 
 */

void LinkedList::add(song &asong){
    cout << "adding songs" << endl;
    node *newNode = new node(asong);
    node* current; 
    if (head==NULL){
        head = newNode;
    }
    else if(head->next && head->s.getViews()<= newNode->s.getViews()){
        newNode->next = head;
        newNode->next->prev = newNode;
        head = newNode;
    }
    else {
        current = head;
        /* Make the appropriate links */
        while (current->next && current->s.getViews()> newNode->s.getViews()){
            current = current->next;
        }
        newNode->next = current->next; 
  
        // if the new node is not inserted 
        // at the end of the list 
        if (current->next != NULL) 
            newNode->next->prev = newNode; 
  
        current->next = newNode; 
        newNode->prev = current; 
    }
    size++;
    cout << "added";
}

/**
 * LinkedList 
 * 
 * @param  {int} m : 
 */

void LinkedList::del(int m){
    cout << "...Calling delete method on..." << m << endl;
    node *ptr = head;
    //change the next and prev only if they are not null
    while(ptr->next){
        if (ptr->s.getViews() < m){
            if(ptr->next != NULL)
                ptr->next->prev = ptr->prev;
            
 
            if(ptr->prev != NULL)
                ptr->prev->next = ptr->next;
               
            delete(ptr); //delete the node
        }
        ptr = ptr->next;
    }
}

    
/**
 * LinkedList 
 * Display all artists in doubly Linked List
 */
void LinkedList::displayArtists(){
    cout << "Displaying Artists" << endl;
    node *curr = head;
    for (curr = head; curr; curr = curr->next)
    {
        cout << "--------------------" << endl;
        cout << "Name: " << curr->a.getName() << endl;
        cout << "Story: " << curr->a.getStory() << endl;
        cout << "Info: " << curr->a.getInfo() << endl;
        cout << "--------------------" << endl;
    }
    cout << endl;
}



/**
 * LinkedList 
 * Display all songs in doubly Linked List
 */
void LinkedList::displaySongs(){
    cout << "s" << endl;
    node *curr = head;
    for (curr = head; curr; curr = curr->next)
    {
        cout << "--------------------" << endl;
        cout << curr->s.getTitle() << endl;
        cout << curr->s.getLength() << endl;
        cout << "Views: " << curr->s.getViews() << endl;
        cout << curr->s.getLikes() << endl;
    }
    cout << "--------------------" << endl;
}



/**
 * LinkedList 
 * 
 * @param  {char*} fileName : 
 * Modify the LinkedList to contain all data from file
 */
void LinkedList::loadArtistFromFile(char * fileName)
{
    ifstream in;
    song Song;
    const int MAX_CHAR = 1001;
    // Artist
    char currName[MAX_CHAR];
    char currStory[MAX_CHAR];
    char currInfo[MAX_CHAR];
    

    in.open(fileName);

	if(!in)
	{
		cerr << "Fail to open " << fileName << " for reading!" << endl;
		exit(1);
	}

    // Split artists and songs by ";"
    // Artist and their songs are on the same line
    while(!in.eof()){
        // Get artist(s)
        in.getline(currName, MAX_CHAR);
        in.getline(currStory, MAX_CHAR);
        in.getline(currInfo, MAX_CHAR);
        artist *Artist =  new artist(currName, currStory, currInfo);
        add(*Artist);
        cout << currName << " added." << endl;
        cout << currStory << " added." << endl;
        cout << currInfo << " added." << endl;
    }
    in.close();
    cout << "File closed" << endl;
}



/**
 * LinkedList 
 * 
 * @param  {char*} Artist : (Artist name serves as file name)
 * @return {LinkedList}   : the new LinkedList which contains all songs for artist
 */
LinkedList LinkedList::loadSongsFromArtist(char * Artist){
    LinkedList alist;
    ifstream in;
    int MAX_CHAR = 1000;
    // song
    char currTitle[MAX_CHAR];
    char currLength[MAX_CHAR];
    char currViews[MAX_CHAR];
    char currLikes[MAX_CHAR];
    // char ext[] = ".txt";

    double clength;
    int cviews;
    int clikes;

    // char *fileName = strcat(Artist, ext);
    
    in.open(Artist);
	if(!in)
	{
		cerr << "Fail to open " << Artist << " load songs from artist for reading!" << endl;
		exit(1);
	}

    while(!in.eof()){
        // Get artist(s)
        in.getline(currTitle, MAX_CHAR);
        in.getline(currLength, MAX_CHAR);
        in.getline(currViews, MAX_CHAR);
        in.getline(currLikes, MAX_CHAR);
        clength = atof(currLength);
        cviews = atoi(currViews);
        clikes = atoi(currLikes);
        song *Song = new song(currTitle, clength, cviews, clikes);
        alist.add(*Song);
    }
    in.close();
    cout << "File Closed" << endl;
    return alist;
}



/**
 * LinkedList 
 * 
 * @param  {char*} fileName : 
 * Get a linkedlist by Loading all artist from file 
 * Add a new artist to said LinkedList
 * Save said artist to the file
 * While creating a new file for songs to be added to artist
 */
void LinkedList::saveArtistToFile(char *fileName){
    ofstream	out;
    int MAX_CHAR = 250;

	out.open(fileName);
	if(!out)
	{
		cerr << "Fail to open " << endl;
		exit(1);
	}

	char newName[MAX_CHAR];
	char newStory[MAX_CHAR];
	char newInfo[MAX_CHAR];
	cout << " ==== Input the artist's name >> ";
    cin.getline(newName, MAX_CHAR);
    
    cout << "\n ==== Input the artist's story >> ";
    cin.getline(newStory, MAX_CHAR);
    
	cout << "\n ==== Input the artist's information >> ";
    cin.getline(newInfo, MAX_CHAR);
    
    artist *Artist =  new artist(newName, newStory, newInfo);
    add(*Artist);
    for(node * curr=head; curr; curr=curr->next)
	{
		out << curr->a.getName() << endl;
        out << curr->a.getStory() << endl;
        out << curr->a.getInfo() << endl;
	}
    out.close();
    
    ofstream f(newName);
}



/**
 * LinkedList 
 * 
 * @param  {char*} Artist : Artist Name
 * @return {LinkedList}   : Songs list for said artist
 * Get a linkedlist by Loading all songs from file 
 * Add a new song to said LinkedList
 * Save said song to the file
 * Returns the song list
 */
LinkedList LinkedList::saveSongsToArtist(char * Artist){
    ofstream out;
    int MAX_CHAR = 250;
    char currTitle[MAX_CHAR];
    char currLength[MAX_CHAR];
    char currViews[MAX_CHAR];
    char currLikes[MAX_CHAR];
    // char ext[] = ".txt";

    double clength;
    int cviews;
    int clikes;
    // char *art = strcpy(art, Artist);

    // char *fileName = strcat(Artist, ext);
    // cout << fileName << endl;

    out.open(Artist);
	if(!out)
	{
		cerr << "Fail to open " << Artist << " save songs to artist for reading!" << endl;
		exit(1);
	}

	cout << " ==== Input the song title >> ";
    cin.getline(currTitle, MAX_CHAR);
    
    cout << " ==== Input the song length >> ";
    cin.getline(currLength, MAX_CHAR);
    
	cout << " ==== Input the song views >> ";
    cin.getline(currViews, MAX_CHAR);

	cout << " ==== Input the song likes >> ";
    cin.getline(currLikes, MAX_CHAR);
    
    clength = atof(currLength);
    cviews = atoi(currViews);
    clikes = atoi(currLikes);
    // song *Song = new song(currTitle, clength, cviews, clikes);
    // LinkedList alist = LinkedList::loadSongsFromArtist(Artist);
    // alist.add(*Song);
    song *Song = new song(currTitle, clength, cviews, clikes);
    LinkedList alist = alist.loadSongsFromArtist(Artist);
    alist.add(*Song);
    for(node * curr=alist.head; curr; curr=curr->next)
	{
		out << curr->s.getTitle() << endl;
        out << curr->s.getLength() << endl;
        out << curr->s.getViews() << endl;
        out << curr->s.getLikes() << endl;
	}
    cout << "Hello";

    out.close();
    return alist;
}

/**
 * 
 * @param  {char*} Artist : The artist of the song
 * @param  {char*} Song   : The song name
 * @return {LinkedList}   : a song list after the change
 * Load artist's song list from file
 * Recursively find the song's name
 * When found, together with findSong setViews/Likes
 * then save the song to file
 */
void LinkedList::editViewsAndLikes(char *Artist, char * Song){
    ofstream out;
    displaySongs();
    node *curr = head;
    cout << curr->s.getTitle() << endl;
    findSong(curr, Song);

    out.open(Artist);
	if(!out)
	{
		cerr << "Fail to open " << Artist << " save songs to artist for reading!" << endl;
		exit(1);
	}

    LinkedList alist = LinkedList::loadSongsFromArtist(Artist);

    for(node * curr=alist.head; curr; curr=curr->next)
	{
		out << curr->s.getTitle() << endl;
        out << curr->s.getLength() << endl;
        out << curr->s.getViews() << endl;
        out << curr->s.getLikes() << endl;
	}
    
    out.close();
    cout << "Done Editing";
}

/**
 * LinkedList 
 * 
 * @param  {node*} curr  : 
 * @param  {char*} Song  : 
 * @return {LinkedList}  : 
 * Using recursion to find the node in the Song list to edit views and likes
 */
void LinkedList::findSong(node * curr, char * Song){
    if (curr->next == NULL){
        int views, likes;
	    cout << " Input your views ==== >> " << endl;
        cin >> views;
	    cin.ignore(MAX_CHAR, '\n');
        cout << " Input your likes ==== >> " << endl;
        cin >> likes;
	    cin.ignore(MAX_CHAR, '\n');
        curr->s.setViews(views);
        curr->s.setLikes(likes);
        return;
    }
    if (curr->s.getTitle()== Song){
            int views, likes;
	        cout << " Input your views ==== >> " << endl;
            cin >> views;
	        cin.ignore(MAX_CHAR, '\n');
            cout << " Input your likes ==== >> " << endl;
            cin >> likes;
	        cin.ignore(MAX_CHAR, '\n');
            curr->s.setViews(views);
            curr->s.setLikes(likes);
    }
    else{
        if(curr->next){
            findSong(curr->next, Song);
        }
    }
}
