#include <iostream>
using namespace std;
#include <cstring>

class song
{
public:
    song();
    song(char *atitle, float alength, int aviews, int alikes);  // Constructor
    ~song();    // destructor

    char *getTitle();
    float getLength();

    void setViews(int aviews);
    void setLikes(int alikes);
    
    int getViews();
    int getLikes();

private:
	char *title;
    float length;
    int views, likes;

	void init(char *atitle, float alength, int aviews, int alikes);
};