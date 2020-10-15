#include <iostream>
#include <cstring>
#include "list.h"
using namespace std;

int mainMenu();

const int MAX_CHAR = 250;

int main()
{
	LinkedList	list;
	LinkedList Eminem;
	char fileName[] = "roster.txt";
	char eminem[] = "Eminem";
	cout << "===== Example Label =====" << endl;
	list.loadArtistFromFile(fileName);

	list.displayArtists();

	Eminem.loadSongsFromArtist(eminem);

	Eminem.displaySongs();

	int choice = mainMenu();

	while (choice > 0)
    {
        switch (choice)
        {
            case 1: 
            {
                cout << "1. Add a new Artist" << endl;
				list.saveArtistToFile(fileName);
				list.displayArtists();
				break;
			}
            case 2: 
            {
                cout << "2. Add a new song for an artist" << endl;
                char newArtist[MAX_CHAR];
                cout << " ==== Input your artist to add song to >> ";
				cin.getline(newArtist, MAX_CHAR);
				list.saveSongsToArtist(newArtist);
				break;
			}
            case 3: 
            {
                cout << "3. Edit the number of views and likes for a song" << endl;
				char newArtist[MAX_CHAR];
                cout << " ==== Input your artist to add song to >> ";
				cin.getline(newArtist, MAX_CHAR);
				list.saveSongsToArtist(newArtist);
                break;
            }
			case 4:
            {
                cout << "4. Display all songs for an artist" << endl;
				cout << " ==== Input your artist to add song to >> ";
				char anotherArtist[MAX_CHAR];
				cin.getline(anotherArtist, MAX_CHAR);
                cout << " Displaying all songs ";
				LinkedList songs = list.loadSongsFromArtist(anotherArtist);
				songs.displaySongs();
				break;
			}
			case 5: 
            {
                cout << "5. Display all artists" << endl;
				list.displayArtists();
				break;
			}
			case 6: 
            {
                cout << "6. Remove all songs with fewer than M views" << endl;
				cout << "4. Display all songs for an artist" << endl;
				cout << " ==== Input your artist to add song to >> ";
				char anotheroneArtist[MAX_CHAR];
				char number[MAX_CHAR];
				cin.getline(anotheroneArtist, MAX_CHAR);
				cout << " Displaying all songs ";
				cout << " ==== Input your artist to add song to >> ";
				cin.getline(number, 12);
				int m = atoi(number);
				LinkedList newsongs = list.loadSongsFromArtist(anotheroneArtist);
				newsongs.del(m);
				break;
			}
            case 7: //exit
            {
                cout << "\n ==== You have chosen: " << endl;
                cout << "\n ==== Thank you so much for using Record Label! ==== " << endl;
                cout << "\n ==== Have a good one! :) ====\n" << endl;
                exit(1);
            }
            default: //input a positive integer outside of 1-6
            {
                cout << "\n!!!Please input a number from 1 to 6 in the menu.!!!\n" << endl;
                break;
            }
        }
		choice = mainMenu();
	}

	cout << "\n!!!!Boom! Your program exploded!!!!\n" << endl;
    return 0;
}

int mainMenu()
{
	cout << "========= CS_RECORD_LABEL ==========\n";

	cout << "\n ====== $$$ Menu options $$$ ====== \n"; //menu options
    cout << "1. Add a new Artist" << endl;
    cout << "2. Add a new song for an artist" << endl;
    cout << "3. Edit the number of views and likes for a song" << endl;
    cout << "4. Display all songs for an artist" << endl;
    cout << "5. Display all artists" << endl;
    cout << "6. Remove all songs with fewer than M views" << endl;
	cout << "7. Exit the program" << endl;

	int selection;
	cout << "\n ==== Enter 1-7 to make your selection ==== " << endl;
	cout << " ==== >> " << endl;
	cin >> selection;
	//cin only gets the first component, use getline to get everything
	cin.ignore(1000, '\n');
	return selection;
}