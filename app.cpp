#include <iostream>
#include <cstring>
#include "list.h"
using namespace std;

int main()
{
	LinkedList	list;
	artist *Eminem = new artist("Eminem", "September 26 – Eminem royalties shares to be sold in an IPO", "Rap");
	song *LoseYourSelf = new song("Lose Yourself", 5.23, 144309378, 654000);

	LinkedList *eminem = new LinkedList();
	list.add(*Eminem);

	list.displayArtists();

	eminem->add(*Eminem);

	eminem->add(*LoseYourSelf);

	eminem->displaySongs();

	artist *Soken = new artist("Masayoshi Soken", "Take over FFXIV OST production role after Nobuo Uemastsu", "Written entire Shadowbringer soundtrack");

	song *Shadowbringers = new song("Shadowbringers", 6.24, 1456788979, 9999906);
	song *StormOfBlood = new song("Storm Of Blood", 3.58, 175678899, 899690);
	song *Triumph = new song("Triumph", 3.14, 1118879, 899688);
	song *Beauty = new song("Beauty's Wicked Wiles", 5.45, 78879, 899000);

	list.add(*Soken);

	list.displayArtists();

	LinkedList *soken = new LinkedList();

	soken->add(*Soken);
	soken->add(*Shadowbringers);
	soken->add(*StormOfBlood);
	soken->add(*Triumph);
	soken->add(*Beauty);

	list.displayArtists();

	soken->displaySongs();

	soken->del(109978);

	soken->displaySongs();

	return 0;
}