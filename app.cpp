/*
	Name: 		Shijie Ren
	Instructor: Li Liang
	Date: 		Oct 15, 2020
	Program: 	Project1/app.cpp
	Info: 		main instructions to run the program and user interface
*/

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
				cout << "--------------------" << endl;
				break;
			}
            case 2: 
            {
                cout << "2. Add a new song for an artist" << endl;
                char newArtist[MAX_CHAR];
                cout << " ==== Input your artist to add song to >> ";
				cin.getline(newArtist, MAX_CHAR);
				LinkedList bArtist;
				bArtist.saveSongsToArtist(newArtist);
				cout << "--------------------" << endl;
				break;
			}
            case 3: 
            {
                cout << "3. Edit the number of views and likes for a song" << endl;
				char newbArtist[MAX_CHAR];
				char newbSong[MAX_CHAR];
				cout << " ==== Input your artist to edit song to >> ";
				cin.getline(newbArtist, MAX_CHAR);
				LinkedList cArtist = cArtist.loadSongsFromArtist(newbArtist);
				cArtist.displaySongs();
				cout << " ==== Input your song to edit >> ";
				cin.getline(newbSong, MAX_CHAR);
				cArtist.editViewsAndLikes(newbArtist, newbSong);
				cArtist.displaySongs();
				cout << "--------------------" << endl;
				break;
            }
			case 4:
            {
                cout << "4. Display all songs for an artist" << endl;
				cout << " ==== Input your artist to display songs to >> ";
				char anotherArtist[MAX_CHAR];
				cin.getline(anotherArtist, MAX_CHAR);
				cout << " ==== Displaying all songs ==== " << endl;
				LinkedList songs = songs.loadSongsFromArtist(anotherArtist);
				songs.displaySongs();
				cout << "--------------------" << endl;
				break;
			}
			case 5: 
            {
                cout << "5. Display all artists" << endl;
				list.displayArtists();
				cout << "--------------------" << endl;
				break;
			}
			case 6: 
            {
                cout << "6. Remove all songs with fewer than M views" << endl;
				cout << " ==== Input your artist to remove views to >> ";
				char anotheroneArtist[MAX_CHAR];
				char number[MAX_CHAR];
				cin.getline(anotheroneArtist, MAX_CHAR);
				LinkedList newsongs = newsongs.loadSongsFromArtist(anotheroneArtist);
				newsongs.displaySongs();
				cout << " Displaying all songs ";
				cout << "\n ==== Input your M number >> ";
				int m;
				cin >> m;
				cin.ignore(MAX_CHAR, '\n');
				newsongs.del(m);
				newsongs.saveSongsToArtist(anotheroneArtist);
				cout << "--------------------" << endl;
				break;
			}
            case 7: //exit
            {
                cout << "\n ==== You have chosen to Exit ==== " << endl;
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
	cout << "\n ====== $$$ Case Sensitive $$$ ====== \n"; //menu options
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