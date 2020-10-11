#include <ostream>
#include <cstring>
#include "song.h"
using namespace std;

song::song() : title(nullptr), length(0), views(0), likes(0){};

song::song(char *atitle, float alength, int aviews, int alikes){
    this->title = new char[strlen(atitle) + 1];
    strcpy(this->title, atitle);
    this->length = alength;
    this->views = aviews;
    this->likes = alikes;
}

song::~song(){
    if (this->title)
    {
        delete[] this->title;
    }
    this->title = nullptr;
}

char *song::getTitle(){
    return title;
}
float song::getLength(){
    return length;
}

void song::setViews(int aviews){
    this->views = aviews;
}
void song::setLikes(int alikes){
    this->likes = alikes;
}

int song::getViews(){
    return views;
}
int song::getLikes(){
    return likes;
}