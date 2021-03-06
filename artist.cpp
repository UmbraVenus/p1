/*
	Name: 		Shijie Ren
	Instructor: Li Liang
	Date: 		Oct 15, 2020
	Program: 	Project1/artist.cpp
	Info: 		Implementation of basic artist class - data only
*/

#include <ostream>
#include <cstring>
#include "artist.h"
using namespace std;

artist::artist() : name(nullptr), story(nullptr), info(nullptr){};

/**
 * artist::artist 
 * 
 * @param  {char*} name  : 
 * @param  {char*} story : 
 * @param  {char*} info  : 
 */

artist::artist(char *name, char *story, char * info){
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->story = new char[strlen(story) + 1];
    strcpy(this->story, story);
    this->info = new char[strlen(info) + 1];
    strcpy(this->info, info);
}

artist::~artist(){
    if (this->name)
    {
        delete[] this->name;
    }
    this->name = nullptr;
}

char *artist::getName(){
    return name;
}

char* artist::getStory(){
    return story;
}
char* artist::getInfo(){
    return info;
}