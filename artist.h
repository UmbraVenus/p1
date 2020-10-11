#include <iostream>
using namespace std;
#include <cstring>

class artist
{
public:
	artist();
	artist(artist& aartist);    // One single object
    artist(char *name, char *story, char * info);
    ~artist();

    char *getName();
    char *getStory();
    char *getInfo();

private:
    char *name;
    char *story;
    char *info;
    void init(char *name, char *story, char * info);
};